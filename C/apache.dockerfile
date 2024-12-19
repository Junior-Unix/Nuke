# Use the official Apache HTTP Server image
FROM httpd:2.4

# Install necessary packages to compile C code
RUN apt-get update && \
    apt-get install -y gcc make && \
    apt-get clean

# Create a directory for the C program
RUN mkdir /usr/local/apache2/htdocs/c_program

# Add the C source file
COPY hello.c /usr/local/apache2/htdocs/c_program/hello.c

# Compile the C program
RUN gcc /usr/local/apache2/htdocs/c_program/hello.c -o /usr/local/apache2/htdocs/c_program/hello.cgi

# Set the correct permissions
RUN chmod +x /usr/local/apache2/htdocs/c_program/hello.cgi

# Configure Apache to execute CGI scripts and listen on port 8080
RUN echo "Listen 8080" >> /usr/local/apache2/conf/httpd.conf && \
    echo "ScriptAlias /cgi-bin/ /usr/local/apache2/htdocs/c_program/" >> /usr/local/apache2/conf/httpd.conf && \
    echo "<Directory \"/usr/local/apache2/htdocs/c_program\">" >> /usr/local/apache2/conf/httpd.conf && \
    echo "    Options +ExecCGI" >> /usr/local/apache2/conf/httpd.conf && \
    echo "    AddHandler cgi-script .cgi" >> /usr/local/apache2/conf/httpd.conf && \
    echo "</Directory>" >> /usr/local/apache2/conf/httpd.conf

# Expose port 8080
EXPOSE 8080

# Start Apache server
CMD ["httpd-foreground"]
# Para levantar este container, siga os seguintes passos:
# 1. Construa a imagem Docker usando o comando:
#    docker build -t nome-da-imagem .
# 2. Execute o container usando o comando:
#    docker run -d -p porta-local:porta-container --name nome-do-container nome-da-imagem
#    Substitua "porta-local" pela porta que deseja expor no host e "porta-container" pela porta que o serviço está escutando no container.
#    Substitua "nome-da-imagem" pelo nome que você deu à imagem no passo anterior.
#    Substitua "nome-do-container" pelo nome que você deseja dar ao container.