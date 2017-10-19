#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>

#include "data/database.h"

#include "core/catalogmodel.h"
#include "core/jobsmaster.h"
#include "core/faces.h"

#include "gui/catalogwidget.h"
#include "gui/rushinfowidget.h"
#include "gui/playerwidget.h"
#include "gui/tagswidget.h"
#include "gui/catalogtreewidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeEvent(QCloseEvent *event);

public slots:
    void addVideo();
    void playVideo(const QString& filepath);

    void addTags();
    void transcode(const QString& command_preset);
    void faceRecognition();
    void addRushToCatalog();
    void removeRushFromCatalog();
    void exportDatabase();
    void importDatabase();

    void onSelectionChanged();
    void onShowJobsProgress();
    void onFaceRecognitionTraining();

    void refreshTheme();

protected:
    void readSettings();
    void writeSettings();

    void createTranscodingActions();

private:

    void createMenus();

    QList<QAction *> m_context_actions;
    QList<QAction *> m_transcode_actions;

    Database m_db;
    Faces m_faces;
    CatalogModel *m_catalog;

    PlayerWidget *m_player;
    CatalogWidget *m_view;
    RushInfoWidget *m_media_info;
    TagsWidget *m_tag_widget;
    CatalogTreeWidget *m_bin_tree_widget;

    QSplitter *m_main_splitter;
    QSplitter *m_right_splitter;

    JobsMaster m_job_master;

};

#endif // MAINWINDOW_H
