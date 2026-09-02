# Guia Bàsica de C++ per a PRO1

Aquesta documentació acadèmica està dissenyada per acompanyar els estudiants de primer curs en l'aprenentatge de la programació en C++, seguint el pla d'estudis de l'assignatura PRO1 a la UPC-FIB.

L'objectiu principal és proporcionar una base sòlida mitjançant explicacions teòriques estructurades, resolució de problemes i l'anàlisi de codi pràctic per evitar els errors de compilació més freqüents.

## Estructura de la Documentació

El contingut està dividit en dues grans seccions que abracen des dels fonaments del llenguatge fins a les estructures de dades bidimensionals i l'algorísmia bàsica.

* **Primera Meitat:**
    * **1. Funcionament C++ i Compilació:** Introducció a l'entorn, declaració de variables i estructures condicionals.
    * **2. Iteracions (Bucles):** Control de flux mitjançant estructures de repetició i lectura seqüencial.
    * **3. Funcions:** Modularitat del codi i pas de paràmetres.
    * **4. Structs:** Agrupació de variables per a la creació de tipus de dades personalitzats.
    * **5. Vectors:** Emmagatzematge i tractament de dades en seqüències unidimensionals.
* **Segona Meitat:**
    * **6. Recursivitat:** Resolució de problemes complexos mitjançant crides a la pròpia funció.
    * **7. Matrius:** Gestió de dades en estructures bidimensionals (taules).
    * **8. Algorismes Fonamentals:** Mètodes estàndard d'ordenació i cerca (inserció, dicotòmica, etc.).

**Metodologia de cada tema:**
Cada mòdul s'estructura en un únic fitxer que inclou la teoria detallada i els exemples de codi integrats a l'explicació. Al final de cada pàgina trobaràs el **`final.cpp`**, un programa complet i executable que consolida tots els conceptes de la lliçó.

## Configuració de l'Entorn de Desenvolupament

Per programar en C++ cal disposar d'un **editor de codi** (com [VSCode](https://code.visualstudio.com/), [Zed](https://zed.dev/) o [Neovim](https://neovim.io/)) o un **IDE** (com [Xcode](https://developer.apple.com/xcode/) per a macOS o [Visual Studio 2026](https://visualstudio.microsoft.com/)) i un compilador. Selecciona el teu sistema operatiu per veure les instruccions d'instal·lació del compilador `g++`:

=== "Windows (WSL)"

    Es recomana utilitzar el Windows Subsystem for Linux (WSL) per disposar d'un entorn de desenvolupament nadiu.

    1. Obre una terminal PowerShell com a administrador i executa:
       ```powershell
       wsl --install -d Ubuntu
       ```
    2. Segueix les instruccions en pantalla per configurar l'usuari i la contrasenya.
    3. Reinicia l'equip si el sistema ho demana.
    4. Obre la nova terminal d'Ubuntu i instal·la les eines de compilació:
       ```bash
       sudo apt update && sudo apt upgrade
       sudo apt install build-essential
       ```

=== "macOS"

    macOS inclou les eines de compilació a través de la línia de comandes d'Xcode.

    1. Obre l'aplicació Terminal.
    2. Executa la següent comanda per instal·lar els components necessaris:
       ```bash
       xcode-select --install
       ```
    3. Confirma el quadre de diàleg que apareixerà a la pantalla.

=== "Arch Linux"

    Instal·lació per a Arch Linux i distribucions derivades (com CachyOS o Manjaro).

    1. Obre la terminal i executa:
       ```bash
       sudo pacman -Syu
       sudo pacman -S base-devel
       ```

=== "Ubuntu / Debian"

    Instal·lació per a distribucions basades en la paqueteria APT.

    1. Obre la terminal i executa:
       ```bash
       sudo apt update && sudo apt upgrade
       sudo apt install build-essential
       ```

=== "Fedora" 

    Instal·lació per a distribucions que utilitzen el gestor de paquets DNF.

    1. Obre la terminal i executa:
       ```bash
       sudo dnf update
       sudo dnf install gcc-c++
       ```

---

Per verificar que la instal·lació s'ha realitzat correctament en qualsevol dels sistemes, executa `g++ --version` a la terminal. Hauria de mostrar la versió actual del compilador.

## Crèdits
* **Autor:** Dídac Molina (aso).
* **Agraïments:** A Oriol Vitutia ([@ItssUri](https://github.com/ItssUri)) per la preparació, desenvolupament teòric i implementació de codi de la secció de Matrius.
