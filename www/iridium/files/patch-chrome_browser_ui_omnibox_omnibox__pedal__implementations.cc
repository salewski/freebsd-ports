--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2025-05-07 06:48:23 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -1985,7 +1985,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
   return omnibox::kShareMacChromeRefreshIcon;
 #elif BUILDFLAG(IS_WIN)
   return omnibox::kShareWinChromeRefreshIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return omnibox::kShareLinuxChromeRefreshIcon;
 #else
   return omnibox::kShareChromeRefreshIcon;
