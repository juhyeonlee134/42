FROM debian:11.0

RUN mkdir -p /run/mysqld
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y mariadb-server

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/run.sh /etc/mysql/run.sh

EXPOSE 3306

ENTRYPOINT [ "/bin/bash", "/etc/mysql/run.sh" ]