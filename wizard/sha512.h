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

  Wizard's Toolkit secure hash algorithm methods.
*/
#ifndef _WIZARDSTOOLKIT_SHA512_H
#define _WIZARDSTOOLKIT_SHA512_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

typedef struct _SHA512Info
  SHA512Info;

extern WizardExport SHA512Info
  *AcquireSHA512Info(void),
  *DestroySHA512Info(SHA512Info *);

extern WizardExport const StringInfo
  *GetSHA512Digest(const SHA512Info *);

extern WizardExport unsigned int
  GetSHA512Blocksize(const SHA512Info *),
  GetSHA512Digestsize(const SHA512Info *);

extern WizardExport void
  InitializeSHA512(SHA512Info *),
  FinalizeSHA512(SHA512Info *),
  UpdateSHA512(SHA512Info *,const StringInfo *);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
