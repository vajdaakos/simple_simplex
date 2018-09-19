#include "gui_plugin_loader.h"
#include <QDir>
#include <QActionGroup>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <QPluginLoader>

gui_plugin_loader::gui_plugin_loader(QObject *parent, MainWindow *w) : QObject(parent)
{
    this->parent_=parent;
    main_window=w;
}

void gui_plugin_loader::load_plugins(QDir plugins_dir)
{
    main_window->central_widget=new QStackedWidget(main_window);
    main_window->setCentralWidget(main_window->centralWidget());

    auto *gui_plugin_group=new QActionGroup (main_window);
    gui_plugin_group->setExclusive(true);

    plugins_dir.cd("plugins");
    plugins_dir.cd("gui_plugins");
    foreach (QString fileName, plugins_dir.entryList(QDir::Files)) {

        QPluginLoader pluginLoader(plugins_dir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin) {


            Mainwindow_Gui_Plugin_Interface* gui_interface = qobject_cast<Mainwindow_Gui_Plugin_Interface*>(plugin);
            if (gui_interface)
            {
                QAction* menu_action=new QAction(gui_interface->Name(),main_window);
                QVariant v = qVariantFromValue((void *) gui_interface);
                menu_action->setData(v);
                main_window->gui_plugin_menu->addAction(menu_action);
                menu_action->setCheckable(true);
                gui_plugin_group->addAction(menu_action);
                connect(main_window->gui_plugin_menu,SIGNAL(triggered(QAction*)),this,SLOT(set_gui(QAction*)));
                main_window->central_widget->addWidget(qobject_cast<QWidget*>(plugin));
                connect(parent_,SIGNAL(set_indulo_feladat_model_view(QStandardItemModel*)),dynamic_cast<QObject*>(gui_interface),SLOT(do_set_indulo_model_view(QStandardItemModel*)));
                connect(parent_,SIGNAL(set_indulo_matrix_model_view(QStandardItemModel*)),dynamic_cast<QObject*>(gui_interface),SLOT(do_set_indulo_matrix_model_view(QStandardItemModel*)));
                connect(parent_,SIGNAL(set_utolso_elotti_allapot_model_view(QStandardItemModel*)),dynamic_cast<QObject*>(gui_interface),SLOT(do_set_utolso_elotti_allapot_model_view(QStandardItemModel*)));
                connect(parent_,SIGNAL(set_utolso_allapot_model_view(QStandardItemModel*)),dynamic_cast<QObject*>(gui_interface),SLOT(do_set_utolso_allapot_model_view(QStandardItemModel*)));
                connect(parent_,SIGNAL(set_kanonikus_alak_model_view(QStandardItemModel*)),dynamic_cast<QObject*>(gui_interface),SLOT(do_set_kanonikus_alak_model_view(QStandardItemModel*)));
                connect(parent_,SIGNAL(indulo_feladat_changed()),dynamic_cast<QObject*>(gui_interface),SLOT(do_when_indulo_feladat_changed()));
                connect(parent_,SIGNAL(external_exercise_loaded(int,int)),dynamic_cast<QObject*>(gui_interface),SLOT(do_when_external_exercise_loaded(int,int)));
                connect(parent_,SIGNAL(set_delegate_for_numbers(QStyledItemDelegate*)),dynamic_cast<QObject*>(gui_interface),SLOT(do_set_delegate_for_numbers(QStyledItemDelegate*)));
                connect(parent_,SIGNAL(set_non_numeric_delegate(QItemDelegate*)),dynamic_cast<QObject*>(gui_interface),SLOT(do_set_non_numeric_delegate(QItemDelegate*)));
                connect(parent_,SIGNAL(button_kezd_clicked(int, int)),dynamic_cast<QObject*>(gui_interface),SLOT(do_when_button_kezd_clicked(int, int)));

                connect(dynamic_cast<QObject*>(gui_interface),SIGNAL(sor_oszlop_db(int,int)),parent_,SLOT(variable_numbers_defined(int,int)));
                connect(dynamic_cast<QObject*>(gui_interface),SIGNAL(make_kanonikus()),parent_,SLOT(do_when_make_kanonikus()));
                connect(dynamic_cast<QObject*>(gui_interface),SIGNAL(make_indulo_matrix()),parent_,SLOT(do_when_make_indulo_matrix()));
                connect(dynamic_cast<QObject*>(gui_interface),SIGNAL(szamol()),parent_,SLOT(do_when_szamol_clicked()));
                connect(dynamic_cast<QObject*>(gui_interface),SIGNAL(vegigszamol(bool)),parent_,SLOT(do_when_vegigszamol(bool)));
                connect(parent_,SIGNAL(szamoldvegig(bool)),dynamic_cast<QObject*>(gui_interface),SLOT(do_when_vegigszamol_changed(bool)));
                connect(parent_,SIGNAL(got_kanonikus_clicked()),dynamic_cast<QObject*>(gui_interface),SLOT(do_when_got_kanonikus_clicked()));
                connect(dynamic_cast<QObject*>(gui_interface),SIGNAL(kanonikus_clicked()),parent_,SLOT(do_when_kanonikus_clicked()));
                connect(parent_,SIGNAL(got_indulo_matrix_clicked()),dynamic_cast<QObject*>(gui_interface),SLOT(do_when_got_indulo_matrix_clicked()));
                connect(dynamic_cast<QObject*>(gui_interface),SIGNAL(indulo_matrix_clicked()),parent_,SLOT(do_when_indulo_matrix_clicked()));
                if(fileName.contains("_default"))
                {
                    menu_action->setChecked(true);
                    main_window->central_widget->setCurrentWidget(dynamic_cast<QWidget*>(gui_interface));
                }
            }
        }
    }
    main_window->setCentralWidget(main_window->central_widget);
    emit_signals_to_set_models_of_views();
    emit_signals_to_set_delegates();
    emit qobject_cast<Simplex_method_calculator*>(parent_)->szamoldvegig(qobject_cast<Simplex_method_calculator*>(parent_)->vegigszamolom);

}
void gui_plugin_loader::set_gui(QAction* menuitem)
{
     QVariant v = menuitem->data();
     auto *gui = reinterpret_cast<Mainwindow_Gui_Plugin_Interface *>(v.value<void *>());
     main_window->central_widget->setCurrentWidget(dynamic_cast<QWidget*>(gui));
}

void gui_plugin_loader::emit_signals_to_set_models_of_views()
{
    emit qobject_cast<Simplex_method_calculator*>(parent_)->set_indulo_feladat_model_view(qobject_cast<Simplex_method_calculator*>(parent_)->indulo_feladat);
    emit qobject_cast<Simplex_method_calculator*>(parent_)->set_kanonikus_alak_model_view(qobject_cast<Simplex_method_calculator*>(parent_)->kanonikus_alak);
    emit qobject_cast<Simplex_method_calculator*>(parent_)->set_indulo_matrix_model_view(qobject_cast<Simplex_method_calculator*>(parent_)->indulo_matrix);
    emit qobject_cast<Simplex_method_calculator*>(parent_)->set_utolso_elotti_allapot_model_view(qobject_cast<Simplex_method_calculator*>(parent_)->utolso_elotti_allapot);
    emit qobject_cast<Simplex_method_calculator*>(parent_)->set_utolso_allapot_model_view(qobject_cast<Simplex_method_calculator*>(parent_)->utolso_allapot);

}

void gui_plugin_loader::emit_signals_to_set_delegates()
{
    emit qobject_cast<Simplex_method_calculator*>(parent_)->set_delegate_for_numbers(qobject_cast<QStyledItemDelegate*>(qobject_cast<Simplex_method_calculator*>(parent_)->delegate_for_numbers));
    emit qobject_cast<Simplex_method_calculator*>(parent_)->set_non_numeric_delegate(qobject_cast<QItemDelegate*>(qobject_cast<Simplex_method_calculator*>(parent_)->non_numeric_delegate));

}
