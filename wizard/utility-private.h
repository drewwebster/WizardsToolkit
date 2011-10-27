/*
  Copyright 1999-2011 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.

  You may not use this file except in compliance with the License.
  obtain a copy of the License at

    http://www.wizards-toolkit.org/script/license.php

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  Wizards' Toolkit private utility methods.
*/
#ifndef _WIZARDSTOOLKIT_UTILITY_PRIVATE_H
#define _WIZARDSTOOLKIT_UTILITY_PRIVATE_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

/*
  Windows UTF8 compatibility methods.
*/

static inline int access_utf8(const char *path,int mode)
{
#if !defined(WIZARDSTOOLKIT_WINDOWS_SUPPORT) || defined(__CYGWIN__) || defined(__MINGW32__)
  return(access(path,mode));
#else
   int
     count,
     status;

   WCHAR
     *path_wide;

   path_wide=(WCHAR *) NULL;
   count=MultiByteToWideChar(CP_UTF8,0,path,-1,NULL,0);
   path_wide=(WCHAR *) AcquireQuantumMemory(count,sizeof(*path_wide));
   if (path_wide == (WCHAR *) NULL)
     return(-1);
   count=MultiByteToWideChar(CP_UTF8,0,path,-1,path_wide,count);
   status=_waccess(path_wide,mode);
   path_wide=RelinquishWizardMemory(path_wide);
   return(status);
#endif
}

static inline FILE *fopen_utf8(const char *path,const char *mode)
{
#if !defined(WIZARDSTOOLKIT_WINDOWS_SUPPORT) || defined(__CYGWIN__) || defined(__MINGW32__)
  return(fopen(path,mode));
#else
   FILE
     *file;

   int
     count;

   WCHAR
     *mode_wide,
     *path_wide;

   path_wide=(WCHAR *) NULL;
   count=MultiByteToWideChar(CP_UTF8,0,path,-1,NULL,0);
   path_wide=(WCHAR *) AcquireQuantumMemory(count,sizeof(*path_wide));
   if (path_wide == (WCHAR *) NULL)
     return((FILE *) NULL);
   count=MultiByteToWideChar(CP_UTF8,0,path,-1,path_wide,count);
   count=MultiByteToWideChar(CP_UTF8,0,mode,-1,NULL,0);
   mode_wide=(WCHAR *) AcquireQuantumMemory(count,sizeof(*mode_wide));
   if (mode_wide == (WCHAR *) NULL)
     {
       path_wide=RelinquishWizardMemory(path_wide);
       return((FILE *) NULL);
     }
   count=MultiByteToWideChar(CP_UTF8,0,mode,-1,mode_wide,count);
   file=_wfopen(path_wide,mode_wide);
   mode_wide=RelinquishWizardMemory(mode_wide);
   path_wide=RelinquishWizardMemory(path_wide);
   return(file);
#endif
}

static inline int open_utf8(const char *path,int flags,int mode)
{
#if !defined(WIZARDSTOOLKIT_WINDOWS_SUPPORT) || defined(__CYGWIN__) || defined(__MINGW32__)
  return(open(path,flags,mode));
#else
   int
     count,
     status;

   WCHAR
     *path_wide;

   path_wide=(WCHAR *) NULL;
   count=MultiByteToWideChar(CP_UTF8,0,path,-1,NULL,0);
   path_wide=(WCHAR *) AcquireQuantumMemory(count,sizeof(*path_wide));
   if (path_wide == (WCHAR *) NULL)
     return(-1);
   count=MultiByteToWideChar(CP_UTF8,0,path,-1,path_wide,count);
   status=_wopen(path_wide,flags,mode);
   path_wide=RelinquishWizardMemory(path_wide);
   return(status);
#endif
}

static inline FILE *popen_utf8(const char *command,const char *type)
{
#if !defined(WIZARDSTOOLKIT_WINDOWS_SUPPORT) || defined(__CYGWIN__) || defined(__MINGW32__)
  return(popen(command,type));
#else
   FILE
     *file;

   int
     count;

   WCHAR
     *type_wide,
     *command_wide;

   command_wide=(WCHAR *) NULL;
   count=MultiByteToWideChar(CP_UTF8,0,command,-1,NULL,0);
   command_wide=(WCHAR *) AcquireQuantumMemory(count,sizeof(*command_wide));
   if (command_wide == (WCHAR *) NULL)
     return((FILE *) NULL);
   count=MultiByteToWideChar(CP_UTF8,0,command,-1,command_wide,count);
   count=MultiByteToWideChar(CP_UTF8,0,type,-1,NULL,0);
   type_wide=(WCHAR *) AcquireQuantumMemory(count,sizeof(*type_wide));
   if (type_wide == (WCHAR *) NULL)
     {
       command_wide=RelinquishWizardMemory(command_wide);
       return((FILE *) NULL);
     }
   count=MultiByteToWideChar(CP_UTF8,0,type,-1,type_wide,count);
   file=_wpopen(command_wide,type_wide);
   type_wide=RelinquishWizardMemory(type_wide);
   command_wide=RelinquishWizardMemory(command_wide);
   return(file);
#endif
}

static inline int remove_utf8(const char *path)
{
#if !defined(WIZARDSTOOLKIT_WINDOWS_SUPPORT) || defined(__CYGWIN__) || defined(__MINGW32__)
  return(unlink(path));
#else
   int
     count,
     status;

   WCHAR
     *path_wide;

   path_wide=(WCHAR *) NULL;
   count=MultiByteToWideChar(CP_UTF8,0,path,-1,NULL,0);
   path_wide=(WCHAR *) AcquireQuantumMemory(count,sizeof(*path_wide));
   if (path_wide == (WCHAR *) NULL)
     return(-1);
   count=MultiByteToWideChar(CP_UTF8,0,path,-1,path_wide,count);
   status=_wremove(path_wide);
   path_wide=RelinquishWizardMemory(path_wide);
   return(status);
#endif
}

static inline int rename_utf8(const char *source,const char *destination)
{
#if !defined(WIZARDSTOOLKIT_WINDOWS_SUPPORT) || defined(__CYGWIN__) || defined(__MINGW32__)
  return(rename(source,destination));
#else
   int
     count,
     status;

   WCHAR
     *destination_wide,
     *source_wide;

   source_wide=(WCHAR *) NULL;
   count=MultiByteToWideChar(CP_UTF8,0,source,-1,NULL,0);
   source_wide=(WCHAR *) AcquireQuantumMemory(count,sizeof(*source_wide));
   if (source_wide == (WCHAR *) NULL)
     return(-1);
   count=MultiByteToWideChar(CP_UTF8,0,source,-1,source_wide,count);
   count=MultiByteToWideChar(CP_UTF8,0,destination,-1,NULL,0);
   destination_wide=(WCHAR *) AcquireQuantumMemory(count,
     sizeof(*destination_wide));
   if (destination_wide == (WCHAR *) NULL)
     {
       source_wide=RelinquishWizardMemory(source_wide);
       return(-1);
     }
   count=MultiByteToWideChar(CP_UTF8,0,destination,-1,destination_wide,count);
   status=_wrename(source_wide,destination_wide);
   destination_wide=RelinquishWizardMemory(destination_wide);
   source_wide=RelinquishWizardMemory(source_wide);
   return(status);
#endif
}

static inline int stat_utf8(const char *path,struct stat *attributes)
{
#if !defined(WIZARDSTOOLKIT_WINDOWS_SUPPORT) || defined(__CYGWIN__) || defined(__MINGW32__)
  return(stat(path,attributes));
#else
   int
     count,
     status;

   WCHAR
     *path_wide;

   path_wide=(WCHAR *) NULL;
   count=MultiByteToWideChar(CP_UTF8,0,path,-1,NULL,0);
   path_wide=(WCHAR *) AcquireQuantumMemory(count,sizeof(*path_wide));
   if (path_wide == (WCHAR *) NULL)
     return(-1);
   count=MultiByteToWideChar(CP_UTF8,0,path,-1,path_wide,count);
   status=wstat(path_wide,attributes);
   path_wide=RelinquishWizardMemory(path_wide);
   return(status);
#endif
}

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif