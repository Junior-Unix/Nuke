FROM mysql:latest

# Set root password
ENV MYSQL_ROOT_PASSWORD root

# Allow root login from any host
RUN echo "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION;" > /docker-entrypoint-initdb.d/01-root-login.sql

# Expose MySQL port
EXPOSE 3306

# Start MySQL server
CMD ["mysqld"]
# # Path: Nuke/JS/mysql.dockerfile
# Compare this snippet from Nuke/JS/Dockerfile:
# #Dockerfile para criar um servidor web apache
# #Imagem base
# FROM httpd:2.4
# #Porta exposta
# EXPOSE 80
# #Diretório compartilhado
# VOLUME "$PWD/:/usr/local/apache2/htdocs"
#
#docker build -t mysql-server -f /d:/Git/Nuke/JS/mysql.dockerfile .
#docker run --name "servidor_mysql" -d -p 3306:3306 -e MYSQL_ROOT_PASSWORD=root mysql-server
#docker exec -it <nome_do_container> mysql -uroot -p
