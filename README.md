# AOCF - Another OpenGL Context Framework

**AOCF** (Another OpenGL Context Framework) é uma biblioteca simples e leve para criação de janelas e gerenciamento de contexto OpenGL.  
O objetivo inicial é oferecer algo semelhante ao [GLFW](https://www.glfw.org/), com uma API simples, clara e fácil de integrar em projetos C/C++ modernos.  
No futuro, planejo expandir as funcionalidades, tornando o AOCF mais próximo de algo como a [SDL](https://www.libsdl.org/), com suporte a áudio, entrada e manipulação de arquivos.

---

## ✨ Objetivo

Desenvolver uma biblioteca multiplataforma para criação de janelas e contexto OpenGL, voltada inicialmente para **uso pessoal e aprendizado**.  
Apesar de ser um projeto educacional, o código é escrito com qualidade e com foco em ser compreensível e de fácil manutenção.

---

## ✅ Funcionalidades

### Contexto OpenGL
- ✅ Criação de janelas (Windows e Linux)
- ✅ Criação de contexto OpenGL
- ✅ Loop de renderização (eventos + swap buffers)
- 🔜 Suporte a V-Sync

### Entrada
- ✅ Captura de teclado
- 🔜 Captura de mouse (posição, botões e wheel)
- 🔜 Detecção de eventos (keydown, keyup, etc.)

### Sistema
- 🔜 Informações sobre monitor/tela (resolução, DPI, etc.)
- 🔜 Suporte a tempo/frame time

### Futuro
- 🔜 Suporte a áudio
- 🔜 Manipulação de arquivos
- 🔜 Suporte a gamepads/joysticks
- 🔜 Compilação para macOS
- 🔜 Sistema de logs (debug/info/warning/error)

---

## 🤔 Por que usar?

Sinceramente? Talvez você **não deva usar**... ainda!  
Esse projeto está em estágio inicial e ainda não é melhor que alternativas já consolidadas.  
Porém, se você gosta de projetos pequenos, educativos e fáceis de entender, pode valer a pena dar uma olhada!  
Toda sugestão e ajuda são bem-vindas. 😄

---

## 🧠 Filosofia

- Código simples e modular
- Documentação clara
- Aprendizado em primeiro lugar

---

## 🖥️ Plataformas Suportadas

- ✅ Windows
- 🔜 Linux
- 🔜 macOS (contribuições são bem-vindas!)

---

## 🔧 Instalação

*Por enquanto, você pode clonar o repositório e compilar com CMake:*

```bash
git clone https://github.com/seu-usuario/AOCF.git
cd AOCF
mkdir build && cd build
cmake ..
make
