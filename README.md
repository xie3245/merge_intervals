### Merge Intervals
#### Bearbeitungszeit:
Das Projekt an sich hat ca. eine Stunde gekostet (ohne diese README)

#### Wie ist die Laufzeit Ihres Programms? 
Sorting: O(nLogn)  
Merging: O(n)

#### Wie kann die Robustheit sichergestellt werden, vor allem auch mit Hinblick auf sehr große Eingaben?
- Wenn mit "sehr großen Eingaben" große Zahlen, die nicht mehr durch den Datentype representiert werden können, gemeint ist:
Ich habe hier keine UI gemacht. Allerdings sollten die Eingaben, die der Benutzer per UI eingegeben hat, geprüft werden. Im Fehlerfall kann man eine Fehlermeldung ausgeben um den Benutzer mitzuteilen, dass die Eingaben nicht bearbeitet werden können.
Wichtig ist meiner Meinung nach, die Grenzen zu definieren und nach außer klar zu machen. 

- Wenn mit "sehr großen Eingaben" gemeint wird, dass die Anzahl der Intervalle zu groß ist:
In diesem Fall könnte eine Exception geworfen werden. Die merge methode bietet "strong guarantee" an, also die zu mergende Liste wird nicht verändert. Memory Leaks werden auch nicht entstehen.

#### Wie verhält sich der Speicherverbrauch ihres Programms?
Der STL Container bringt natürlich overhead mit. Außerdem wird für std::vector mehr Speicher allokiert als die eigentliche Größe damit neue Elemente später effizient hinzugefügt werden können. Die Reallokation passiert aber nicht bei jedem push_back.
Theoretisch ist der Speicherbrauch linear. Praktisch kann es variieren.

### Bemerkungen:
- Leider habe ich keine UI fürs Eingeben mit implementiert. Man kann in den Unit Tests sehen z.B. dass die Beispiel Liste in der Aufgabe Beschreibung erfolgreich gemergt wird. 
- CMake und C++11 sind fürs Bauen des Prgoramms nötig. Das Projekt kann man out-of-the-box unter Linux bauen. Fürs bauen einfach den Script build.sh ausführen. Die Binaries sind unter build/bin zu finden. Unit Tests werden nach dem Bauen automatsich ausgeführt.
- Es gibt im Code keine Kommentare. Ich hoffe, mein Code ist selbsterklärend genug.
- Als Typ der Zahlen wird uint32_t genommen. Dieser lässt sich aber leicht im Code ändern. 
