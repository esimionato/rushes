#ifndef FACERECOGNIZER_H
#define FACERECOGNIZER_H

#include <QObject>
#include <QMap>
#include <QSize>
#include <QPair>
#include <QVector>
#include <QDir>

#include "opencv2/opencv.hpp"
#include "opencv2/face.hpp"

typedef QVector<QPair<cv::Mat,cv::Rect>> FaceD;

class Faces : public QObject
{
    Q_OBJECT
public:
    explicit Faces(QObject *parent = nullptr);

    QStringList parseVideo(const QString& filepath);
    void setTrainingSamplesFolder(const QString& path);
    void resetTrainingSamplesFolder();

    QMap<QString, QStringList> tagUnknwonFaces();
    QString whoIsThis(cv::Mat image, cv::Rect face);

    void clear();

protected:
    int getIdByName(const QString& name);

signals:
    void progress(int frame);

public slots:

private:
    std::vector<cv::Mat> m_images;
    std::vector<int> m_labels;

    std::vector<cv::Mat> m_strangers_imgs;
    std::vector<int> m_strangers_lbls;

    QMap<QString,int> m_peoples;
    QMap<int, QString> m_peoples_bimap;

    cv::Ptr<cv::face::FaceRecognizer> m_recognition_model;
    cv::Ptr<cv::face::FaceRecognizer> m_strangers_recognition_model;
    cv::CascadeClassifier m_haar_cascade;

    QSize m_samples_size;
    QMap<QString,FaceD> m_unknown_faces;
    QDir m_training_samples_path;
};

#endif // FACERECOGNIZER_H
