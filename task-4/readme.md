# 4 Užduotis

### Sąlyga

3 variantas

> Sudaryti dvipusį sąrašą. Parašyti procedūrą, kuri išmeta iš sąrašo mažiausią elementą.

### Naudojimas

Sukompiliuoti programai naudokite komandą `make` ir paleiskite atsiradusį `bin/output` failą.

Sukompiliuoti testams naudokite komandą `make tests` ir paleiskite atsiradusį `bin/test` (be 's' gale) failą.

### Kodavimo standartas

Galite rasti [čia](./coding-style.md).

### Refleksija

Užduotį spręsti sekėsi sėkmingai ir buvo gana linksma. Labai padėjo laiko susiplanavimas ir beveik visur tilpau į laiko rėmus (šiek tiek nuvertinau meniu sukūrimo užtrunkamą laiką). Testų vykdymas ir principas labai primityvus, tačiau manau, kad šiai užduočiai užteks. Su didelėmis problemomis programuodamas nesusidūriau, kadangi susiplanavau viską iš anksto. Maniau, jog nuskaitytų duomenų pavertimas į sąrašo elementus (struct) užtruks ilgiau, tačiau pasirodo tai nėra problematiška ir galima panaudoti `malloc`. Taip pat pavyko pernaudoti tam tikras dalis iš trečios užduoties, tad išnaudotas laikas sumažėjo. Šiaip linked list'as kaip duomenų struktūra man buvo seniai pažįstama, tad nebuvo sunku suprasti ir padaryti šią užduotį.

### Laiko paskirstymas

| Užduotis                                                               | Numatytas laikas | Užtruktas laikas |
| ---------------------------------------------------------------------- | ---------------- | ---------------- |
| Aprašyti kodavimo standartą                                            | 30min            | 29,5min          |
| Implementuoti įvesties failo pavadinimo nuskaitymą                     | 10min            | 5min             |
| Implementuoti failo nuskaitymą (kartu su error handling)               | 30min            | 20min            |
| Sukurti dvipusio sąrašo duomenų struktūrą                              | 10min            | 4min             |
| Implementuoti nuskaitytų duomenų pavertimą į sąrašo elementus (struct) | 45min            | 19min            |
| Implementuoti sąrašo išspausdinimo funkciją                            | 15min            | 7,5min           |
| Implementuoti vartotojo meniu                                          | 30min            | 46min            |
| Implementuoti elemento išmetimo funkciją                               | 30min            | 28min            |
| Sukurti unit testus funkcijoms                                         | 45min            | 41min            |
| Sudaryti Makefile                                                      | 30min            | 11,5min          |
| Dokumentacijai (refleksijai ir t.t.) ir edge cases testavimui          | 30min            | 12,5min          |
| Iš viso                                                                | 305min           | 224min           |
