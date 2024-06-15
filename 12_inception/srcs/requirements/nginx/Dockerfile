FROM debian:11.0

RUN apt-get -y update
RUN apt-get -y install nginx

COPY conf/default.conf /etc/nginx/sites-available/default.conf

EXPOSE 433

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]