//[dirkarnez/mariadb-connector-c-playground](https://github.com/dirkarnez/mariadb-connector-c-playground/tree/main)
/*
   char query[1024];
   strcpy(query, "SELECT * FROM information_schema.tables WHERE `TABLE_SCHEMA` = ?");

   char data[255];
   strcpy(data, "sys");
   
   MYSQL_BIND my_bind[1];
   memset(my_bind, '\0', sizeof(my_bind));
   
   my_bind[0].buffer_type= MYSQL_TYPE_STRING;
   my_bind[0].buffer= (void *)&data;
   my_bind[0].buffer_length= strlen(data);
   
   // should be 102
   fprintf(stdout, "%d", my_stmt_result(conn, query, my_bind));
*/
