FROM centos:latest

# Instalação do Node.js
RUN curl -sL https://rpm.nodesource.com/setup_14.x | bash -
RUN yum install -y nodejs

# Instalação do SSH Server
RUN yum install -y openssh-server
RUN mkdir /var/run/sshd

# Configuração do SSH
RUN echo 'root:root' | chpasswd
RUN sed -ri 's/PermitRootLogin\S+.*/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -ri 's/UsePAM yes/#UsePAM yes/g' /etc/ssh/sshd_config

# Exposição das portas
EXPOSE 22
EXPOSE 3090

# Comando para iniciar o SSH Server
CMD ["/usr/sbin/sshd", "-D"]

# Volume persistente na pasta atual
VOLUME ["/workspace"]
#docker build -t myimage -f /workspaces/Nuke/JS/ubuntuSSH.dockerfile .
FROM centos:latest

# Instalação do Node.js
RUN curl -sL https://rpm.nodesource.com/setup_14.x | bash -
RUN yum install -y nodejs

# Instalação do SSH Server
RUN yum install -y openssh-server
RUN mkdir /var/run/sshd

# Configuração do SSH
RUN echo 'root:root' | chpasswd
RUN sed -ri 's/PermitRootLogin\S+.*/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -ri 's/UsePAM yes/#UsePAM yes/g' /etc/ssh/sshd_config

# Configuração do iptables com proxy na porta 3128
RUN iptables -t nat -A OUTPUT -p tcp --dport 80 -j DNAT --to-destination proxy_ip:3128
RUN iptables -t nat -A OUTPUT -p tcp --dport 443 -j DNAT --to-destination proxy_ip:3128

# Exposição das portas
EXPOSE 22
EXPOSE 3090

# Comando para iniciar o SSH Server
CMD ["/usr/sbin/sshd", "-D"]

# Volume persistente na pasta atual
VOLUME ["/workspace"]
#docker build -t myimage -f /workspaces/Nuke/JS/ubuntuSSH.dockerfile .
