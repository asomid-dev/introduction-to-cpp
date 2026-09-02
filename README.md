# 🚀 Guia Bàsica de C++

Una guia de C++ pensada per a principiants de l'assignatura de PRO1 (UPC-FIB).

Aquest repositori està pensat per ajudar els estudiants a entendre C++ des de zero. Aquí trobaràs la teoria ben mastegada, exemples pràctics i els trucs que et salvaran dels errors més comuns de compilació.

## 🛠️ Dependències

Per començar a programar, necessitaràs:
- Un [Editor de Codi](https://ca.wikipedia.org/wiki/Editor_de_codi_font) (p. ex. [VSCode](https://code.visualstudio.com/), [Zed](https://zed.dev/), [neovim](https://neovim.io/)) o un [IDE](https://ca.wikipedia.org/wiki/Entorn_integrat_de_desenvolupament) (p. ex. [Visual Studio 2026](https://visualstudio.microsoft.com/es/downloads/), [Xcode](https://developer.apple.com/xcode/) (MacOS))
- Compilador de C++ 
- Terminal Linux

En cas que utilitzeu Windows, podeu instal·lar una terminal Linux i el compilador de C++ de la següent forma:

<details>
<summary>🪟 <strong>Instal·lació WSL (Windows Subsystem for Linux)</strong></summary>

**1. Obriu una terminal PowerShell i executeu:**

```PowerShell 
wsl.exe --install -d [Distro]
``` 

Podeu fer servir la distro que vulgueu, però us recomano Ubuntu. Exemple:
```PowerShell
wsl.exe --install -d Ubuntu
```

Us demanarà que poseu una contrasenya i coses vàries; només heu d'emplenar la informació que us demanen.

**2. Un cop instal·lat WSL, heu d'obrir Ubuntu i actualitzar i instal·lar el compilador:**
```PowerShell
# Primer a PowerShell obrim WSL amb l'ordre:
wsl.exe
```

Un cop entrem a Ubuntu, farem:
```bash
sudo apt update
sudo apt upgrade
# Instal·lem el compilador de C++ (g++) i altres eines
sudo apt install build-essential
```

</details>

En el cas de tenir Linux com a sistema operatiu, podeu seguir els següents passos:
<details>
<summary>🐧 <strong>Instal·lació del compilador a Linux</strong></summary>

**1. Obriu una terminal.**

**2. Actualitzeu els paquets del sistema:**
```bash
sudo apt update
sudo apt upgrade
```

**3. Instal·leu el compilador de C++ (g++) i altres eines de compilació:**
```bash
sudo apt install build-essential
```

**4. Comproveu que s'ha instal·lat correctament:**
```bash
g++ --version
```
Hauria de mostrar la versió del compilador instal·lada.

> **Nota:** Si utilitzeu una distribució diferent de Debian/Ubuntu (com Fedora, Arch, etc.), l'ordre d'instal·lació canvia:
> - **Fedora:** `sudo dnf install gcc-c++`
> - **Arch:** `sudo pacman -S base-devel`

</details>

## 📚 Estructura del Repositori

El contingut es divideix per temes en les següents carpetes:

### PRIMERA MEITAT
- **📂 1. Funcionament Cpp i Compilar:** L'essencial per arrencar. Funcionament, variables i condicions.
- **📂 2. Iteracions (_Bucles_):** Estructures de repetició i lectura seqüencial de dades.
- **📂 3. Funcions:** Com fer funcions auxiliars que executin un codi específic. 
- **📂 4. Structs:** Com agrupar diferents variables sota un mateix nom per crear tipus de dades personalitzats.
- **📂 5. Vectors:** Com emmagatzemar informació en seqüències unidimensionals.

### SEGONA MEITAT
- **📂 6. Recursivitat:** Tècnica on una funció es crida a si mateixa per resoldre problemes més petits.
- **📂 7. Matrius:** Com emmagatzemar informació en estructures bidimensionals (taules).
- **📂 8. Algorismes Fonamentals:** Mètodes clàssics per cercar i ordenar dades eficientment (cerca dicotòmica, ordenació per inserció...).

**Cada carpeta té:**
- 📖 Un arxiu **`TEMARI.md`** amb una explicació dels continguts (teoria).
- 💻 Una carpeta **`Code`** amb arxius `.cpp` amb codi d'exemple (amb comentaris).
- 🎯 Un arxiu **`final.cpp`**. En aquest arxiu, el codi implementat contindrà tots els elements explicats al tema.

## Agraïments
- [@ItssUri](https://github.com/ItssUri) per la seva col·laboració redactant i preparant tot el temari corresponent a les Matrius.

## Socials

[![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5.svg?logo=linkedin&logoColor=white)](https://www.linkedin.com/in/asomid/) 
[![Twitter/X](https://img.shields.io/badge/Twitter%2FX-%23000000.svg?logo=x&logoColor=white)](https://x.com/b3ak01)
[![Discord](https://img.shields.io/badge/Discord-aso-%235865F2.svg?logo=discord&logoColor=white)](https://discord.gg/JhzSdGkU)

> **Nota:** Si us plau, utilitzeu l'enllaç de Discord **únicament** per a dubtes relacionats amb el temari, els exercicis o l'assignatura de PRO1.

## Author

[![GitHub](https://img.shields.io/badge/asomid--dev-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/asomid-dev)
