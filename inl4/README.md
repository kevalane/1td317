# Tasks - Strings and Arrays

The purpose of this task is to write a program reading a txt file and 
counting the frequency of individual letters. From this, the program 
should be able to 'guess' the language said text is written in.

It's divided into two parts:

### Part A

1. Take input from keyboard
2. Count frequency for every letter A-Z
3. Print total number of letters
4. Print a table of frequencies for every letter.

### Part B

Implement the following functions:

1. berakna_histogram_abs() from part A
2. abs_till_rel() from frequency to relative freq
3. plotta_histogram_rel() print a histogram
4. tolkning() decide the language it's written in
5. namn_pa_fil() take intput of filename
6. inlasning() read said file

## Tests

Test conducted on 06/17/2022, all passing. Test reports split up in 
partA and partB respectively.

### I lösningsförslagen tipsar vi om att du ska skapa/ladda hem en 
fil med bara lite innehåll medan man testar sitt program. Varför, tror 
du?

Bra för att manuellt kunna räkna så att metoderna 
berakna_histogram_abs(), abs_till_rel() m.m. returnerar rätt värden. 
Hade det varit riktigt stora filer vi jobbat med hade även argumentet 
kunnat göras för att det går snabbare att köra mindre filer, varför 
iterationer på implementationssteget kan göras snabbare - något som 
underlättar utvecklingen.


### Texten i filen lagerlof.txt innehåller de svenska bokstäverna å, 
ä och ö. Som programmet fungerar nu räknas inte dessa bokstäver med 
alls. Hur skulle man gå tillväga för att också inkludera å, ä och ö i 
histogrammet. Du behöver inte ge en program-lösning, men resonera 
kring hur man skulle kunna göra.

Implementera stöd för "ASCII expanded" som går att ses här: 
https://www.ascii-code.com/. å=229, ä=228 och ö=246. Man får kolla 
upp versalerna också, och ändra berakna_histogram_abs() som 
nödvändigt. Man skulle även behöva ändra i vår konstant, för att 
kvadratfelet skulle ta hänsyn till detta. Slutligen skulle den 
globala variabeln med antalet bokstäver inkrementeras med 3.
