CREATE DATABASE IF NOT EXISTS `test` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `test`;
TABLE `test`.`test` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `description` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
```
I have a simple table with 3 columns, id, name and description.
I have a simple form that allows me to add a new row to the table.
I have a simple form that allows me to edit a row in the table.
I have a simple form that allows me to delete a row in the table.
I have a simple form that allows me to search the table.
CREATE DATABASE IF NOT EXISTS `test` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `test`;
CREATE EXTENSION IF NOT EXISTS "uuid-ossp"; -- Add this line to enable UUID extension
CREATE TABLE IF NOT EXISTS `test` (
    `id` UUID DEFAULT uuid_generate_v4() NOT NULL,
    `name` varchar(255) NOT NULL,
    `description` text NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

I have a simple form that allows me to sort the table.
