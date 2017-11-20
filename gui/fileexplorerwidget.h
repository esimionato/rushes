#ifndef FILEEXPLORERWIDGET_H
#define FILEEXPLORERWIDGET_H

#include <QSplitter>
#include <QTreeView>
#include <QFileSystemModel>

#include "thumbnailview.h"
#include "data/database.h"

class FileExplorerWidget : public QSplitter
{
    Q_OBJECT
public:
    FileExplorerWidget(Database &db, QWidget *parent = 0);
    ~FileExplorerWidget();

    QString currentDirectory() const;

    ThumbnailView *view() const;

protected:
    void writeSettings();
    void readSettings();

protected slots:
    void onDirectoryChanged(const QModelIndex &index);

private:
    QTreeView *m_tree_view;
    ThumbnailView *m_thumbnail_view;
    QFileSystemModel *m_model;
    Database &m_db;
    QDir m_current_dir;
};

#endif // FILEEXPLORERWIDGET_H
