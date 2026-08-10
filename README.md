# 🚀 Guia Bàsica de C++ (C Plus Plus)

A beginner-friendly C++ guide built for the PRO1 course (UPC-FIB). 

Aquest repositori està pensat per ajudar els estudiants a entendre C++ des de zero. Aquí trobaràs la teoria ben mastegada, exemples pràctics i els trucs que et salvaran dels errors més comuns de compilació.

## 🛠️ Dependències

Per començar a programar, necessitaràs:
- Un [IDE](https://ca.wikipedia.org/wiki/Entorn_integrat_de_desenvolupament) (p. ex. [VSCode](https://code.visualstudio.com/), [Zed](https://zed.dev/), [neovim](https://neovim.io/)) 
- Terminal Linux. 

En cas que utilitzeu Windows, podeu instal·lar una terminal Linux de la següent forma:

<details>
<summary>🪟 <strong>Instal·lació WSL (Windows Subsystem for Linux)</strong></summary>

1. Obriu una terminal PowerShell i executeu: 

```PowerShell 
wsl.exe --install -d [Distro]
``` 

Podeu fer servir la distro que vulgueu, però us recomano Ubuntu. Exemple:
```PowerShell
wsl.exe --install -d Ubuntu
```

Us demanarà que poseu una contrasenya i coses vàries; només heu d'emplenar la informació que us demanen.

2. Un cop instal·lat WSL, heu d'obrir Ubuntu i actualitzar i instal·lar el compilador:
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

## 📚 Estructura del Repositori

El contingut es divideix per temes en les següents carpetes:

- **📂 1. Com funciona C++ i com compilar:** L'essencial per arrencar. Funcionament, variables i condicions.
- **📂 2. Iteracions (_Bucles_):** Estructures de repetició i lectura seqüencial de dades.
- **📂 3. Contenidors:** Com emmagatzemar informació (vectors, matrius...).
- **📂 4. Recursivitat (_Totalment Opcional_):** Aquest és opcional perquè s'explica a la 2a meitat de PRO1.

**Cada carpeta té:**
- 📖 Un arxiu **`TEMARI.md`** amb una explicació dels continguts (teoria).
- 💻 Una carpeta **`Code`** amb arxius `.cpp` amb codi d'exemple (amb comentaris).
- 🎯 Un arxiu **`final.cpp`**. En aquest arxiu, el codi implementat contindrà tots els elements explicats al tema.

## Socials

[![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5.svg?logo=linkedin&logoColor=white)](https://www.linkedin.com/in/asomid/) 
[![Twitter/X](https://img.shields.io/badge/Twitter%2FX-%23000000.svg?logo=x&logoColor=white)](https://x.com/b3ak01)
[![Discord](https://img.shields.io/badge/Discord-aso-%235865F2.svg?logo=discord&logoColor=white)](https://discord.gg/JhzSdGkU)

## Author

[![GitHub](https://img.shields.io/badge/asomiD--cat-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/asomiD-cat)
