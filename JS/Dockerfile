FROM ubuntu:latest
LABEL MAINTAINER name="Junior-Unix" email="sonjunior@live.com"
RUN apt-get update
RUN apt-get install -y openssh-server
RUN mkdir /var/run/sshd

RUN echo 'root:root' |chpasswd 
RUN sed -ri 's/^#PermitRootLogin\s+.*/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -ri 's/UsePAM yes/#UsePAM yes/g' /etc/ssh/sshd_config
RUN mkdir /root/.ssh
EXPOSE 22
EXPOSE 3090

CMD ["/usr/sbin/sshd", "-D"]
# Path: JS/ubuntuSSH.dockerfile