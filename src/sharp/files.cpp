/*
 * gnote
 *
 * Copyright (C) 2011,2017 Aurimas Cernius
 * Copyright (C) 2009 Hubert Figuiere
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <glib/gstdio.h>
#include <glibmm.h>
#include <giomm/file.h>

#include "files.hpp"


namespace sharp {


  bool file_exists(const Glib::ustring & file)
  {
    return Glib::file_test(file, Glib::FILE_TEST_EXISTS)
           && Glib::file_test(file, Glib::FILE_TEST_IS_REGULAR);
  }


  Glib::ustring file_basename(const Glib::ustring & p)
  {
    const Glib::ustring filename = Glib::path_get_basename(p);
    const Glib::ustring::size_type pos = filename.find_last_of('.');

    return Glib::ustring(filename, 0, pos);
  }

  Glib::ustring file_dirname(const Glib::ustring & p)
  {
    return Glib::path_get_dirname(p);
  }


  Glib::ustring file_filename(const Glib::ustring & p)
  {
    return Glib::path_get_basename(p);
  }

  void file_delete(const Glib::ustring & p)
  {
    g_unlink(p.c_str());
  }


  void file_copy(const Glib::ustring & source, const Glib::ustring & dest)
  {
    Gio::File::create_for_path(source)->copy(Gio::File::create_for_path(dest), Gio::FILE_COPY_OVERWRITE);
  }

  void file_move(const Glib::ustring & from, const Glib::ustring & to)
  {
    g_rename(from.c_str(), to.c_str());
  }
}

