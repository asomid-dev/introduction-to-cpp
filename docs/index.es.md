# Guía Básica de C++ para PRO1

Esta documentación académica está diseñada para acompañar a los estudiantes de primer curso en el aprendizaje de la programación en C++, siguiendo el plan de estudios de la asignatura PRO1 en la UPC-FIB.

El objetivo principal es proporcionar una base sólida mediante explicaciones teóricas estructuradas, resolución de problemas y el análisis de código práctico para evitar los errores de compilación más frecuentes.

## Estructura de la Documentación

El contenido está dividido en dos grandes secciones que abarcan desde los fundamentos del lenguaje hasta las estructuras de datos bidimensionales y la algoritmia básica.

* **Primera Mitad:**
    * **1. Funcionamiento Cpp y Compilar:** Introducción al entorno, declaración de variables y estructuras condicionales.
    * **2. Iteraciones (Bucles):** Control de flujo mediante estructuras de repetición y lectura secuencial.
    * **3. Funciones:** Modularidad del código y paso de parámetros.
    * **4. Structs:** Agrupación de variables para la creación de tipos de datos personalizados.
    * **5. Vectores:** Almacenamiento y tratamiento de datos en secuencias unidimensionales.
* **Segunda Mitad:**
    * **6. Recursividad:** Resolución de problemas complejos mediante llamadas a la propia función.
    * **7. Matrices:** Gestión de datos en estructuras bidimensionales (tablas).
    * **8. Algoritmos Fundamentales:** Métodos estándar de ordenación y búsqueda (inserción, dicotómica, etc.).

**Metodología de cada tema:**
Cada módulo se estructura en un único archivo que incluye la teoría detallada y los ejemplos de código integrados en la explicación. Al final de cada página encontrarás el **`final.cpp`**, un programa completo y ejecutable que consolida todos los conceptos de la lección.

## Configuración del Entorno de Desarrollo

Para programar en C++ es necesario disponer de un **editor de código** (como [VSCode](https://code.visualstudio.com/), [Zed](https://zed.dev/) o [Neovim](https://neovim.io/)) o un **IDE** (como [Xcode](https://developer.apple.com/xcode/) para macOS o [Visual Studio 2026](https://visualstudio.microsoft.com/)) y un compilador. Selecciona tu sistema operativo para ver las instrucciones de instalación del compilador `g++`:

=== "Windows (WSL)"

    Se recomienda utilizar el Windows Subsystem for Linux (WSL) para disponer de un entorno de desarrollo nativo.

    1. Abre una terminal PowerShell como administrador y ejecuta:
        ```powershell
        wsl --install -d Ubuntu
        ```
    2. Sigue las instrucciones en pantalla para configurar el usuario y la contraseña.
    3. Reinicia el equipo si el sistema lo pide.
    4. Abre la nueva terminal de Ubuntu e instala las herramientas de compilación:
        ```bash
        sudo apt update && sudo apt upgrade
        sudo apt install build-essential
        ```

=== "macOS"

    macOS incluye las herramientas de compilación a través de la línea de comandos de Xcode.

    1. Abre la aplicación Terminal.
    2. Ejecuta el siguiente comando para instalar los componentes necesarios:
        ```bash
        xcode-select --install
        ```
    3. Confirma el cuadro de diálogo que aparecerá en la pantalla.

=== "Arch Linux"

    Instalación para Arch Linux y distribuciones derivadas (como CachyOS o Manjaro).

    1. Abre la terminal y ejecuta:
        ```bash
        sudo pacman -Syu
        sudo pacman -S base-devel
        ```

=== "Ubuntu / Debian"

    Instalación para distribuciones basadas en la paquetería APT.

    1. Abre la terminal y ejecuta:
        ```bash
        sudo apt update && sudo apt upgrade
        sudo apt install build-essential
        ```

=== "Fedora" 

    Instalación para distribuciones que utilizan el gestor de paquetes DNF.

    1. Abre la terminal y ejecuta:
        ```bash
        sudo dnf update
        sudo dnf install gcc-c++
        ```

---

Para verificar que la instalación se ha realizado correctamente en cualquiera de los sistemas, ejecuta `g++ --version` en la terminal. Debería mostrar la versión actual del compilador.

## Créditos
* **Autor:** Dídac Molina (aso).
* **Agradecimientos:** A Oriol Vitutia ([@ItssUri](https://github.com/ItssUri)) por la preparación, desarrollo teórico e implementación de código de la sección de Matrices.
