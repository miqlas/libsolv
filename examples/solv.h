/*
 * Copyright (c) 2009, Novell Inc.
 *
 * This program is licensed under the BSD license, read LICENSE.BSD
 * for further information
 */

#ifndef SOLV_H
#define SOLV_H

#include "repo.h"

#define TYPE_UNKNOWN	0
#define TYPE_SUSETAGS	1
#define TYPE_RPMMD	2
#define TYPE_PLAINDIR	3
#define TYPE_DEBIAN     4
#define TYPE_HAIKU      5

#define METADATA_EXPIRE (60 * 15)

struct repoinfo {
  Repo *repo;

  char *alias;
  char *name;
  int enabled;
  int autorefresh;
  char *baseurl;
  char *metalink;
  char *mirrorlist;
  char *path;
  int type;
  int pkgs_gpgcheck;
  int repo_gpgcheck;
  int priority;
  int keeppackages;
  int metadata_expire;
  char **components;
  int ncomponents;

  unsigned char cookie[32];
  unsigned char extcookie[32];
  int incomplete;
};

#endif /* SOLV_H */
