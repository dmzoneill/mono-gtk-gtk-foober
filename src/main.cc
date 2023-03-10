#include <gtkmm.h>
#include <iostream>


#ifdef ENABLE_NLS
#  include <libintl.h>
#endif


/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/gtk_foobar/ui/gtk_foobar.ui" */
#define UI_FILE "src/gtk_foobar.ui"
   
int main (int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);
	
	//Load the Glade file and instiate its widgets:
	Glib::RefPtr<Gtk::Builder> builder;
	try
	{
		builder = Gtk::Builder::create_from_file(UI_FILE);
	}
	catch (const Glib::FileError & ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	Gtk::Window* main_win = 0;
	builder->get_widget("main_window", main_win);
	if (main_win)
	{
		kit.run(*main_win);
	}
	return 0;
}
