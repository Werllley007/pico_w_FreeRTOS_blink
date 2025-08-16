# Tutorial de Configuração do FreeRTOS para Raspberry Pi Pico W

Este tutorial descreve os passos para integrar o FreeRTOS no seu projeto da Raspberry Pi Pico W. Seguindo estas etapas, você conseguirá configurar o kernel do FreeRTOS, importar o repositório necessário, e ajustar o CMakeLists.txt para incluir o FreeRTOS no processo de build.

## Passos para a Configuração do FreeRTOS

### 1. Baixar o FreeRTOS

Primeiro, crie o diretório **libs** e faça o clone do repositório do **FreeRTOS-Kernel**:

```bash
mkdir libs
cd libs
git clone https://github.com/FreeRTOS/FreeRTOS-Kernel.git
```

### 2. Copiar o Arquivo FreeRTOSConfig.h

Em seguida, você precisa copiar o arquivo FreeRTOSConfig.h que se encontra em:
```bash
$(Projeto)/libs/FreeRTOS-Kernel/examples/template_configuration/FreeRTOSConfig.h
```

Copie esse arquivo para a pasta raiz do seu projeto. O caminho final será:

```bash
Projeto/
    ├── libs/
    │    └── FreeRTOS-Kernel/
    ├── CMakeLists.txt
    ├── FreeRTOSConfig.h
    ├── pico_sdk_import.cmake
    └── main.c
```

### 3. Editar o CMakeLists.txt

Agora, edite o arquivo CMakeLists.txt do seu projeto para incluir o FreeRTOS no processo de build. Adicione as seguintes linhas:

#### a. Definir o Caminho do FreeRTOS

No início do arquivo CMakeLists.txt, defina a variável FREERTOS_KERNEL_PATH para apontar para a pasta FreeRTOS-Kernel:
```bash
# Set any variables required for importing libraries
SET(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/FreeRTOS-Kernel)
```
#### b. Incluir o FreeRTOS no Projeto

Em seguida, adicione o FreeRTOS ao processo de build utilizando o comando include e linkando a biblioteca:

```bash
# Pull in FreeRTOS
include(${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

# Add any user requested libraries
target_link_libraries(
        pico_stdlib 
        FreeRTOS-Kernel 
        FreeRTOS-Kernel-Heap4
)
```

Este comando irá incluir o FreeRTOS no seu build, permitindo que você utilize as funcionalidades multitarefa no seu código.

### 4. Estrutura do Projeto

Após seguir esses passos, a estrutura do seu projeto será semelhante à seguinte:
```bash
Projeto/
    ├── build/
    ├── libs/
    │    └── FreeRTOS-Kernel/
    ├── CMakeLists.txt
    ├── FreeRTOSConfig.h
    ├── pico_sdk_import.cmake
    ├── main.c
    └── README.md
```

O FreeRTOSConfig.h foi copiado para a raiz do seu projeto e o CMakeLists.txt foi configurado para incluir o FreeRTOS-Kernel.

### 5. Compilação do Projeto

Agora você pode compilar o projeto com o FreeRTOS incluído. Execute os seguintes comandos na raiz do seu projeto:

```bash
mkdir build
cd build
cmake ..
make
```

Isso irá compilar o código com o FreeRTOS e gerar o binário para a Raspberry Pi Pico W.

## Considerações Finais

Com estas etapas, você configurou com sucesso o FreeRTOS no seu projeto para a Raspberry Pi Pico W. Agora você pode começar a programar com multitarefas e aproveitar os recursos do FreeRTOS, como filas, semáforos e timers.

Se tiver algum problema durante a configuração, verifique se o caminho para o FreeRTOSConfig.h está correto e se o CMakeLists.txt está devidamente configurado.


