mkdir -p /run/mysqld;
chown -R mysql: /run/mysqld;

echo "CREATE DATABASE IF NOT EXISTS $DB_NAME;" > init.sql;
echo "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS';" >> init.sql;
echo "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';" >> init.sql;
echo "FLUSH PRIVILEGES;" >> init.sql;

mysql -u root < init.sql;

mysqld;