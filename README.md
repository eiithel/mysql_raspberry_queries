# mysql_raspberry_queries

The aim of this project is to feed a data base hosted on a PC with sensor data coming from an embarked device such as a raspberry pi in order to provide some domotic services to multiple clients.

The card and the SQL servor belong to the same local network.
For the moment, data recorded correspond to the ambient temperature in my room.
The values recorded are displayed in real time on a web page thanks to a php script which retrieves the informations in the database.

I will use the Qt framework on the client side in order to treat the information.
When the temperature will be too high a mail will be send to my google mail account in order to notice me that something is wrong.

Of course for the moment I use a simple temperature sensor and that is not very useful but the modularity of the code will allow to add any type of sensor to the system.

## raspberry side

![](https://github.com/eiithel/mysql_raspberry_queries/blob/master/documents/UML_UML_queries.png)
 
