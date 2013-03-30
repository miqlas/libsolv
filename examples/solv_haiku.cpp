/*
 * Copyright (c) 2011, Ingo Weinhold <ingo_weinhold@gmx.de>
 *
 * This program is licensed under the BSD license, read LICENSE.BSD
 * for further information
 */

#include <stdio.h>
#include <string.h>

#include <Entry.h>
#include <String.h>
#include <StringList.h>

#include <package/PackageRoster.h>
#include <package/RepositoryCache.h>
#include <package/RepositoryConfig.h>

#include "poolarch.h"

#include "solv_haiku.h"

using namespace BPackageKit;

#if defined(__HAIKU__) && defined(__HAIKU_ARCH_X86)
void set_haiku_x86_pool_arch(Pool *pool)
{
#if (B_HAIKU_ABI & B_HAIKU_ABI_MAJOR) == B_HAIKU_ABI_GCC_2
  pool_setarchpolicy(pool, "x86_gcc2");
#else
  pool_setarchpolicy(pool, "x86");
#endif
}
#endif

struct repoinfo *read_haiku_repoinfos(Pool *pool, int *nrepoinfosp)
{
  // get the repository names
  BPackageRoster roster;
  BStringList repoNames;
  status_t error = roster.GetRepositoryNames(repoNames);
  if (error != B_OK)
    return NULL;

  struct repoinfo *repoinfos = 0;
  int nrepoinfos = 0;

  int repoNameCount = repoNames.CountStrings();
  for (int i = 0; i < repoNameCount; i++)
    {
      const BString& name = repoNames.StringAt(i);
      BRepositoryConfig config;
      error = roster.GetRepositoryConfig(name, &config);
      if (error != B_OK)
        {
          printf("Failed to get config for repository \"%s\". Skipping.\n",
            name.String());
          continue;
        }

      struct repoinfo *cinfo;
	  repoinfos = (struct repoinfo*)solv_extend(repoinfos, nrepoinfos, 1,
	    sizeof(*repoinfos), 15);
	  cinfo = repoinfos + nrepoinfos++;
	  memset(cinfo, 0, sizeof(*cinfo));

	  cinfo->baseurl = strdup(config.BaseURL());
	  cinfo->alias = strdup(config.Name());
	    // TODO: Alias?
	  cinfo->name = strdup(config.Name());
	  cinfo->type = TYPE_HAIKU;
	  cinfo->enabled = 1;
	  cinfo->priority = config.Priority();
	  cinfo->autorefresh = 1;
	  cinfo->repo_gpgcheck = 0;
	  cinfo->metadata_expire = METADATA_EXPIRE;
//      cinfo->components = solv_extend(cinfo->components, cinfo->ncomponents, 1, sizeof(*cinfo->components), 15);
//      cinfo->components[cinfo->ncomponents++] = strdup(compo);
    }

  *nrepoinfosp = nrepoinfos;
  return repoinfos;
}

void get_haiku_installed_status(struct stat *status)
{
  // TODO:...
}

FILE *open_haiku_repo_cache(struct repoinfo *info)
{
  BPackageRoster roster;
  BRepositoryCache cache;
  if (roster.GetRepositoryCache(info->alias, &cache) != B_OK)
    return NULL;

  BPath path;
  if (cache.Entry().GetPath(&path) != B_OK)
    return NULL;

  return fopen(path.Path(), "r");
}

void install_haiku_package(FILE *file)
{
}

void uninstall_haiku_package(Solvable *solvable)
{
}
