# simple_simplex
simplex method calculator in c++/qt under documentation

___


credit Other peoples work: A big THANKS to them


 icon: Tetrahedron by Alexander Skowalsky from the Noun Project


 php-crud-api: Maurits van der Schee, git: https://github.com/mevdschee/php-crud-api.git, link: https://github.com/mevdschee/php-crud-api)



 ___
 ___

Introduction

This applications purpose is to make learning and teaching of simplex method easier.


The app is totally plugin based. The plugins has to be copied in a subfolder of the 'plugins' folder. The folder depends on the cathegory of the plugin. (See \ref plugins_sec "Plugins section")



___
___

Installiation


Just unzip and run!



___
___


Plugins

Each cathegory of plugins implements an interface. The interface defines only what methods has to exist. The app doesn't care about how the plugin provides the functionallity, or even provides or not. If the methods existed, they would be loaded.


Each interface has its own folder in which the plugin are wanted! In each folder has to be plugin whose filename must include the word "default"!



___


Load exercise from external source

  - Folder name: exercise_load_plugins

  - Default plugin: DUE Feladatbank (DUE Exercise Bank)

  - Default plugin filename:

      - linux: Exercise_Load_Plugin_default.so

      - windows: Exercise_Load_Plugin_default1.dll



default_plugin: DUE Feladatbank (DUE Exercise Bank)


Exercises could be loaded from a couple of sources. Files (XML, excel worksheet, CSV, etc.), (various) databases, etc. This plugin uses the exercise bank of the Univerity of Dunaújváros. This exercise bank is a pair of MySQL database and PHP API.


It is not for public use, therefor the URL has been changed in the source code to nonworking example stuff.


___

Gui plugins: GUIs

  - Folder name: gui_plugins

  - Default plugin: Korcsolya (Skate)

  - Default plugin filename:

      - linux: korcsolya_default.so

      - windows: korcsolya_default1.dll


___


Picture Loader Plugins

 - Folder name: picture_load_plugins

 - Default plugin: Elmélet (Theoretics)

 - Default plugin filename:

      - linux: picture_loader_default.so

      - windows: picture_loader_default1.dll


These plugins load graphics. The default plugin loads process diagrams about the simplex algorithm.



___

Pivot Element Selector Plugins


TODO

___


Result Reporter Plugins


TODO

 ___

