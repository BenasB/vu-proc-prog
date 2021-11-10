# 3 Užduotis

### Sąlyga

9 variantas

> Parašyti funkciją, kuri iš duoto teksto išmeta žodžius, kurių vidurinis simbolis yra skaitmuo (tarpų skaičius turi likti nepakitęs).

### Refleksija

Užduotis pasidarė gana greitai, tačiau nuvertinau kiek laiko užtruks padaryti failų nuskaitymą. Maniau, kad užtruks mažiau laiko, bet pasirodo, jog gana problematiška C kalboje nuskaityti eilutę į statinio dydžio masyvą iki '\n' arba tam tikros ribos (mūsų atveju iki 255 simbolių, pagal sąlygą). Kad ir kaip bebūtų, viską, ką norėjau, padaryti pavyko ir lygtai visus reikalavimus išpildžiau. Taip pat išskaidžiau programą į du šaltinio (source) failus, kad Makefile turėtų bent kažkiek prasmės (vienam šaltinio failui kaip ir neapsimoka rašyti Makefile?). Pats eilutės apdorojimo algoritmas veikia pakankamai primityviai, tad galbūt šioje vietoje būtų galima sugalvoti kažką protingiau ir išmaniau.

### Laiko paskirstymas

| Užduotis                                                                             | Numatytas laikas | Užtruktas laikas |
| ------------------------------------------------------------------------------------ | ---------------- | ---------------- |
| Implementuoti argumentų nuskaitymą (failų pavadinimus)                               | 30min            | 31min            |
| Implementuoti failų nuskaitymą (kartu su error handling)                             | 45min            | 59min            |
| Implementuoti algoritmą, kuris nustato žodį, kurį reikia išmesti, ir pakeičia eilutę | 60min            | 65min            |
| Implementuoti failų išrašymą (kartu su error handling)                               | 45min            | 14min            |
| Sudaryti makefile                                                                    | 30min            | 29min            |
| Dokumentacijai (refleksijai ir t.t.) ir edge cases testavimui                        | 30min            | 14min            |
| Iš viso                                                                              | 240min           | 212min           |
