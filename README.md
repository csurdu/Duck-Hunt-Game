# Duck-Hunt-Game
Implemetare joc de tipul Duck Hunt. Pentru inspirație, puteți testa jocul original aici: https://www.duck-hunt.org/. :)

De asemenea, puteti viziona un mic demo construit rapid pe baza frameworkului de laborator care acopera cerintele, avand un aspect vizual minimal :).
https://youtu.be/eyZwa6lDm14


Rațe
Construcție
Rațele sunt reprezentate de câteva primitive geometrice 2D (minimum 4: corp, aripi și cap), poziționate sugestiv. Puteți vedea o construcție propusă a raței în imaginea de mai jos, formată din 4 triunghiuri și un cerc (câte un triunghi pentru corp, aripi și cioc, și capul reprezentat de cerc).



Animare
Pentru a construi rața va fi așadar nevoie de un ansamblu de mai multe obiecte definite manual (vedeți modalitatea de definirea a pătratului din laborator) care se vor mișca împreuna, dar vor avea și animații independente. Astfel, rața:

Va avea o animație de zbor: va da din aripi - puteți aplica de exemplu o rotație simplă pe fiecare aripă
Va zbura în diverse direcții în mod unitar - tot asamblul obiectelor care compun rața se va mișca sau roti împreună
Pentru a obține aceste efecte, recomandăm folosirea de transformări ierarhice: va puteți construi o matrice de transformare a întregii rațe pe care să o aplicați fiecărei primitive în parte, după ce se aplică eventuale transformări individuale ale acestora.

Exemplu de funcționare a transformărilor ierarhice folosind OpenGL și glm 

Definim o structură ierarhică de transformări (relative la o matrice de modelare părinte)
Modificând o transformare pe lanțul ierarhic, aceasta se va propaga tuturor copiilor
Afișare
Ratele apar cate una pe rand pe ecran, astfel incat la un moment dat sa nu fie decat o rata prezenta in scena. In momentul in care o rata este impuscata sau evadeaza se va putea afisa urmatoarea.

Mișcare
Rațele apar în partea de jos a ecranului și își vor începe zborul pe o direcție aleatoare în plan. Continuând pe acea direcție, la un moment dat vor ajunge la marginea ecranului. În această situație, rața trebuie să se “reflecte” și să își continue drumul în direcția aferentă, asemenea unei bile de biliard care lovește marginea mesei. Dacă rața este împușcată, aceasta va cădea pe sol mișcându-se printr-o animație vertical în jos, respectiv dacă evadează va zbura în afara ecranului mișcându-se printr-o animație vertical in sus.



După un număr rezonabil de secunde, în care rața s-a ciocnit de câteva ori de marginea ecranului, aceasta va evada. Numărul de secunde va depinde de viteza cu care se mișcă rața în implementarea voastră, dar propunem să fie în jur de 3-5 secunde pentru a nu sta foarte mult o singură rață pe ecran.
Gameplay
Scopul jocului este ca jucătorul să împuște cât mai multe rațe înainte să rămână fără vieți. Jocul începe cu un număr de vieți disponibile, dintre care se pierde câte una de fiecare dată când o rața reușește să scape fără să fie împușcată.

Rațele apar câte una singură pe ecran, pe rând, fiecare după dispariția (prin evadarea sau împușcarea) celei anterioare. O rață va cădea pe sol când este împușcată și va zbura vertical în sus pentru a simboliza evadarea (sunt descrise deja detalii în secțiunile “Rațe - Afișare” și “Rațe - Mișcare”). Ele se mișcă după regulile descrise la secțiunea “Rațe - Mișcare”. După generarea a câte 5 rațe, viteza de mișcare a acestora va crește și, ca atare, dificultatea jocului va crește.

De exemplu: dacă primele 5 rațe se mișcă la o viteza v0, următoarele 5 ar putea avea viteza v1 = v0 + v0 / 5, următoarele v2 = v0 + 2 * v0 / 5 și așa mai departe, pentru a avea o modificare incrementală a dificultății.
Trasul cu pușca
Pentru a împușca o rață, jucătorul are la dispoziție 3 gloanțe care se reîncarcă de fiecare dată când apare o nouă rață. De fiecare dată când acesta face clic pe ecran, se va considera ca un glonț a fost tras în acel punct pe ecran și numărul de gloanțe disponibile va scădea cu 1. Dacă punctul de pe ecran (detalii secțiunea “Intersecția glonțului cu rața”) care a fost împușcat intersectează rața, ea va fi considerată împușcată, scorul (detalii secțiunea “Scor”) va crește și rața va cădea pe sol (detalii secțiunea “Rațe - Mișcare”).

Intersecția glonțului cu rața
Având în vedere că rațele au o formă destul de complexă, ar fi greu de calculat exact ce puncte de pe ecran se intersectează cu ele. Așadar, le puteți aproxima sub forma unui dreptunghi în care este încadrată rața (similar figurii de mai jos). Pentru a calcula coordonatele colțurilor acestui pătrat, puteți folosi câteva noțiuni de geometrie în plan, aplicate în funcție de coordonatele la care se află punctele de pe silueta raței.

Pătratul încadrator este mult mai ușor de calculat dacă toate coordonatele locale ale primitivelor din care este construită rața sunt calculate față de un punct cât mai apropiat de centrul raței (detalii secțiunea “Rața - Construcție”).

Mai multe detalii despre aproximarea coliziunilor 2D: https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection .

Pentru a afla dacă mouse-ul se află în interiorul dreptunghiului încadrator al raței, trebuie făcută o conversie din coordonate de vizualizare către coordonatele logice în care rața se plimbă pe ecran. Dacă va folosiți de scheletul laboratorului 3, aceste 2 spații de coordonate corespund 1:1 întrucât spațiul de desenare este limitat la rezoluția porții de afișare și se poate considera că poziția cursorului mouse-ului este și poziția sa în coordonate logice. Altfel, va trebui aplicată o transformare similară cu transformarea fereastră - poartă (detaliată tot în laboratorul 3), doar ca inversă. Atenție la corecția coordonatei Y.

După ce cursorul și dreptunghiul se află în același spațiu de coordonate, verificarea intersecției se rezumă la verificarea dacă un punct în plan se află într-un dreptunghi aliniat cu axele Ox și Oy. Detaliile acestui calcul sunt lăsate ca exercițiu pentru student.

Inputul de la mouse se poate trata în funcția “OnMouseMove” din framework. Aceasta are 4 parametri: mouseX, mouseY, deltaX, deltaY. Primele 2 se referă la poziția la care se află cursorul în momentul în care se apelează funcția, în pixeli. Numerotarea începe din colțul stânga-sus al ferestrei de vizualizare în (0, 0). Cei 2 parametri din urmă se referă la deplasarea exactă (tot în pixeli) a cursorului de la poziția sa în frame-ul anterior pana la poziția sa în frame-ul în care a fost apelată funcția. De exemplu, daca mouse-ul s-a mișcat de la poziția (1200, 300) la poziția (1220, 294) în intervalul de la ultimul frame până la cel curent, vom avea următoarele valori: mouseX = 1220, mouseY = 294, deltaX = 20, deltaY = -6.
Evadarea raței
În momentul în care toate cele 3 gloanțe au fost consumate fără a fi fost împușcată rața, aceasta evadează. De asemenea, dacă rața nu a fost împușcată timp de un număr de secunde, va evada. În ambele situații în care rața evadează, jucătorul va pierde o viață (detalii secțiunea “Vieți”) și nu va primi scorul aferent raței respective.
