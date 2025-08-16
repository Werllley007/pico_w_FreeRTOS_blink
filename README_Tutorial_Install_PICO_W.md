# Tutorial: Instalação da Raspberry Pi Pico W no Linux

Este tutorial irá guiá-lo na instalação e configuração do ambiente de desenvolvimento para a Raspberry Pi Pico W em um sistema Linux.

## Passos para a Instalação

### 1. Instalar o Git

Primeiro, instale o **git**, uma ferramenta necessária para clonar os repositórios do SDK e exemplos da Raspberry Pi Pico.

```bash
sudo apt install git
```

### 2. Criar o Diretório de Trabalho

Crie um diretório chamado pico para armazenar o SDK e exemplos da Raspberry Pi Pico.

```bash
mkdir pico
cd pico
```

### 3. Clonar os Repositórios Necessários

Clone os repositórios do pico-sdk (SDK da Raspberry Pi) e pico-examples (exemplos de código para a Raspberry Pi Pico):

```bash
git clone https://github.com/raspberrypi/pico-sdk.git
git clone https://github.com/raspberrypi/pico-examples.git
```

### 4. Inicializar os Submódulos do SDK

Acesse o diretório do pico-sdk e inicialize os submódulos necessários.

```bash
cd pico-sdk
git submodule update --init
```
### 5. Atualizar o Sistema e Instalar Dependências

Atualize o sistema e instale as dependências necessárias para compilar o código da Raspberry Pi Pico.

```bash
sudo apt update
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential
```

### 6. Configurar o Ambiente de Desenvolvimento

Crie um diretório de compilação para os exemplos e configure o ambiente:

```bash
cd /home/werlley/pico/pico-examples
mkdir build
cd build
export PICO_SDK_PATH=/home/werlley/pico/pico-sdk
export PICO_EXTRAS_PATH=/home/werlley/pico/pico-sdk
alias cmakepico='cmake -DPICO_BOARD=pico_w ..'
```

### 7. Compilar um Exemplo

Agora, você pode compilar o exemplo blink (piscando um LED). Navegue até o diretório do exemplo e execute o comando make.

```bash
cd /home/werlley/pico/pico-examples/build/blink
make
```

### 8. Instalar o Minicom para Comunicação Serial

Instale o minicom, uma ferramenta para comunicação serial, para monitorar a saída da sua Raspberry Pi Pico:

```bash
sudo apt-get install minicom
sudo minicom -b 115200 -o -D /dev/ttyACM0
```

### 9. Editar o Arquivo ~/.bashrc

Para configurar variáveis de ambiente e aliases úteis, edite o arquivo ~/.bashrc:

```bash
gedit ~/.bashrc
```

Adicione as seguintes linhas ao arquivo:

```bash
PATH=$PATH:~/toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi/bin/
export PICO_SDK_PATH=/home/werlley/pico/pico-sdk

alias minicompico='sudo minicom -b 115200 -o -D /dev/ttyACM0'
alias rmpico='sudo rm -r ./*'
alias cmakepico='cmake -DPICO_BOARD=pico_w ..'
export PICO_EXTRAS_PATH=~/pico/pico-extras
```

### 10. Configuração do Udev

Para permitir o acesso à Raspberry Pi Pico sem usar sudo, você precisa configurar uma regra no udev. Navegue até o diretório de regras do udev e edite o arquivo 99-picotool.rules:

```bash
cd /etc/udev/rules.d/
gedit 99-picotool.rules
```

Adicione a seguinte regra ao arquivo:

```bash
# Make Raspberry Pi Pico accessible without sudo.

SUBSYSTEM!="usb_device", ACTION!="add", GOTO="rpi2_end"
# Raspberry Pi Pico
ATTR{idVendor}=="2e8a", ATTRS{idProduct}=="0003", MODE="660", GROUP="plugdev"

LABEL="rpi2_end"
```

### 11. Aplicar as Regras do Udev

Depois de adicionar a regra, execute o comando para aplicar as novas configurações:

```bash
sudo udevadm trigger
```

Isso permite que o sistema reconheça a Raspberry Pi Pico sem precisar de privilégios de superusuário.

Agora você tem um ambiente de desenvolvimento completo para programar a Raspberry Pi Pico W. Siga os passos para compilar e transferir programas para a Pico, e use o minicom para monitorar a saída serial.

## Considerações Finais

Este tutorial fornece os passos essenciais para configurar a Raspberry Pi Pico W em um sistema Linux. Após concluir, você pode começar a desenvolver seus projetos e explorar os exemplos fornecidos pela Raspberry Pi.
