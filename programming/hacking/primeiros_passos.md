### Primeiros Passos
Temos que configurar o nosso ambiente de trabalho, que no caso vai ser o 
kali linux, para isso temos algumas opções, utilizaremos a mais convencional que é virtualizar.

Durante a virtualização, ficar atento à placa de rede, quantidade de memória, placa gráfica e tudo mais

após a instalação, temos que realizar as configurações inicias

### Configurando Kali
1. Trocar senha do usuário root
-> sudo su "senha padrão"
-> passwd root
-> digitar nova senha

2. Permitir que o usuário root utilize o ssh
-> configurar arquivo do /etc/ssh/sshd_config
-> vim ou nano /etc/ssh/sshd_config

3. Inicializar o serviço de ssh no kali
-> systemctl start ssh
Tem outra forma de fazer
-> service ssh start

