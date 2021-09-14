#!/bin/bash
die () {
    echo >&2 $'\n'"$@"
    exit 1
}

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

project_root=$(dirname $(dirname $(realpath $0 )))
echo "Project root: $project_root"

[ "$#" -ge 1 ] || die "Error: please specify the main file name (relative to project root)"

if ! [ -f "$1" ]; then
    die "Error: file "$1" does not exist."
fi

if ! [ -f "$project_root/tests/cases.txt" ]; then
    die "Error: cases.txt does not exist, please create it."
fi

ignore=1
if ! [ -f "$project_root/tests/ignore.txt" ]; then
    echo -e "Warning: ignore.txt is missing, proceeding without it.\n"
    ignore=0
fi

echo "Compiling"
gcc $project_root/$1 -o $project_root/bin/output
if [ "$?" -ne 0 ]; then 
    die "Error: compilation failed, tests will not run"
else
    echo -e "Done Compiling\n\nExecuting\n"
fi

test_count=0
passed_count=0
failed_count=0

while read test_name || [ -n "$test_name" ]; do
    [ -z "$test_name" ] && continue

    # Get test input
    read input_data
    while read new_line || [ -n "$new_line" ]; do
        [ -z "$new_line" ] && break
        input_data="${input_data} ${new_line}"
    done
 
    # Get expected outcome
    read expected_data
    while read new_line || [ -n "$new_line" ]; do
        [ -z "$new_line" ] && break
        expected_data="${expected_data} ${new_line}"
    done

    # Run compiled binary
    received_data=$(echo "$input_data" | $project_root/bin/output)

    if [ $ignore = 1 ] ; then
        while read ignore_line || [ -n "$ignore_line" ]; do
            received_data=${received_data/$ignore_line/}
        done < $project_root/tests/ignore.txt
    fi

    # Remove newlines
    received_data=$(echo $received_data | sed ':a;N;$!ba;s/\n\n/ /g')

    ((test_count++))
    if [ "$expected_data" = "$received_data" ]; then 
        echo -e "$test_count. $test_name: ${GREEN}PASSED${NC}"
        ((passed_count++))
    else
        echo -e "$test_count. $test_name: ${RED}FAILED${NC}"
        ((failed_count++))
        echo -e "Expected:\n$expected_data"
        echo -e "Recieved:\n$received_data"
    fi

done < $project_root/tests/cases.txt

echo -e "\nTotal tests: $test_count\nPassed: ${GREEN}$passed_count${NC}\nFailed: ${RED}$failed_count${NC}"