/*
 * Copyright (c) 2011, Ingo Weinhold <ingo_weinhold@gmx.de>
 *
 * This program is licensed under the BSD license, read LICENSE.BSD
 * for further information
 */
 
#ifndef SOLV_HAIKU_H
#define SOLV_HAIKU_H

#include <stdio.h>

#include "solv.h"

#ifdef __cplusplus
extern "C" {
#endif

void set_haiku_x86_pool_arch(Pool *pool);
struct repoinfo *read_haiku_repoinfos(Pool *pool, int *nrepoinfosp);
void get_haiku_installed_status(struct stat *status);
FILE *open_haiku_repo_cache(struct repoinfo *info);
void install_haiku_package(FILE *file);
void uninstall_haiku_package(Solvable *solvable);

#ifdef __cplusplus
}
#endif

#endif /* SOLV_HAIKU_H */
