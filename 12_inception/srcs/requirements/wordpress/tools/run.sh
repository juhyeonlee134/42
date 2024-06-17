#!/bin/bash

cd /var/www/html;
wget https://wordpress.org/latest.tar.gz;
tar -xvf latest.tar.gz;
rm -rf /var/www/html/wp-admin /var/www/html/wp-content /var/www/html/wp-includes;
mv wordpress/* /var/www/html/;
rm -rf latest.tar.gz wordpress;

mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
mv /wp-config.php /var/www/html/wp-config.php

sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 9000/g' /etc/php/7.4/fpm/pool.d/www.conf

/usr/sbin/php-fpm7.4 -F