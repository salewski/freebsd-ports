--- enforcer/src/keystate/zonelist_import_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/keystate/zonelist_import_cmd.h
@@ -29,6 +29,6 @@
 #ifndef _KEYSTATE_ZONELIST_IMPORT_CMD_H_
 #define _KEYSTATE_ZONELIST_IMPORT_CMD_H_
 
-struct cmd_func_block zonelist_import_funcblock;
+extern struct cmd_func_block zonelist_import_funcblock;
 
 #endif /* _KEYSTATE_ZONELIST_IMPORT_CMD_H_ */
