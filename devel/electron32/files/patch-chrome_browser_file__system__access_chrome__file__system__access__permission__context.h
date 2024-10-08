--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.h.orig	2024-08-30 11:29:38 UTC
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.h
@@ -432,7 +432,7 @@ class ChromeFileSystemAccessPermissionContext
       FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
       kDontBlockChildren},
   #endif
-  #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+  #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // On Linux also block access to devices via /dev.
       {kNoBasePathKey, FILE_PATH_LITERAL("/dev"), kBlockAllChildren},
       // And security sensitive data in /proc and /sys.
