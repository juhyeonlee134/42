FROM debian:11.0

RUN apt-get -y update
RUN apt-get -y install nginx

COPY conf/default /etc/nginx/sites-available/default

RUN ln -s /etc/nginx/sites-available /etc/nginx/sites-enabled
RUN rm /etc/nginx/sites-enabled/default

EXPOSE 433

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]