--- chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2025-05-07 06:48:23 UTC
+++ chrome/browser/ui/webui/settings/appearance_handler.cc
@@ -32,7 +32,7 @@ void AppearanceHandler::RegisterMessages() {
       "useDefaultTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseTheme,
                           base::Unretained(this), ui::SystemTheme::kDefault));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   web_ui()->RegisterMessageCallback(
       "useGtkTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseTheme,
