/*
 * Copyright (c) 2013, Novell Inc.
 *
 * This program is licensed under the BSD license, read LICENSE.BSD
 * for further information
 */

#include "repo.h"

extern int repo_add_rpmdb_pubkeys(Repo *repo, int flags);
extern Id repo_add_pubkey(Repo *repo, const char *key, int flags);
