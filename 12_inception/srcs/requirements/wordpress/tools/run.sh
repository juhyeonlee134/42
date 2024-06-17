sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 9000/g' /etc/php/7.4/fpm/pool.d/www.conf

cd /var/www/html;
wget https://wordpress.org/latest.tar.gz;
tar -xvf latest.tar.gz;
mv wordpress/* /var/www/html/;
RUN rm -rf latest.tar.gz wordpress;

/usr/sbin/php-fpm7.4 -F