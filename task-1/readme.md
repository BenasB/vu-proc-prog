# 1 Užduotis

### Sąlyga

6 variantas

> Įvesti sveikų skaičių seką, kurios pabaiga žymima skaičiumi 0. Išvesti narių, kurie yra sveikų skaičių kvadratai, skaičių.

### Refleksija

Pats kvadratų tikrinimo algoritmas nebuvo sunkus, o daugiausiai reikėjo užtrukti prie įvesties validavimo, kadangi norėjau, jog programa priimtų tik sveikuosius skaičius (..., -2, -1, 0, 1, 2, ...). Validavimo esmė nėra sudėtinga (imame simbolius vieną po kito ir žiūrime ar susidaro tinkamas skaičius), tačiau implementacija gaunasi nemaža (galima palyginti programą [su validacija](./main.c) ir programą [be validacijos](./no-validation.c)). Stengiausi testuojant išgauti visus įmanomus scenarijus, kur programa galėtų suklysti, o kad tai padaryti būtų patogiau, susikūriau paprastą [bash skriptą](./tests/run_tests.sh), kuris atlieka unit testus, aprašytus faile [cases.txt](./tests/cases.txt). Naudojau TDD metodiką - pasirašiau test case'us ir tik tada kūriau programą, kuri įvykdytų šiuos testus.