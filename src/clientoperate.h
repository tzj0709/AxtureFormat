﻿/*!
 *  @brief     转换控制页面
 *  @details
 *  @author    zyd
 *  @version   1.0
 *  @date      2020.03.09
 *  @warning
 *  @copyright NanJing RenGu.
 */
#ifndef CLIENTOPERATE_H
#define CLIENTOPERATE_H

#include <QWidget>
#include <QButtonGroup>

#include "head.h"

#include "global.h"
#include "startthreads.h"
#include "threadswitch.h"

#define MAXTHREAD 4

class ViewModel;
class ViewDelegate;

namespace Ui {
class ClientOperate;
}

class ClientOperate : public QWidget
{
    Q_OBJECT

public:
    explicit ClientOperate(QWidget *parent = 0);
    ~ClientOperate();
signals:
    void switchObjFile(AxturePage,QString,QString);

private slots:
    void openAxureProject();
    void clearAxureTable();
    void chooseUserFilePath();

    void viewFile(QString htmlFilePath);
    void deletFileData(QString filePath);
    void switchLineHtmlFile(QString htmlFilePath);

    void startSwitchFiles();
    void slot_QtVersionGroupClicked(int);
    void slot_DirPathGroupClicked(int);
    void appendErrorRecord(QString record);
    void appendWarningRecord(QString record);
    void appendRecord(QString record);
    void updateProcess(AxturePage newProcessInfo);
    void controlWidget(bool state);

private:
    void initView();
    void findFixedFiles();
    bool isRepeatedFile(QString filePath);
    void updateTableModel();

    bool checkJsCssExisted(QString path,bool isSinglePage = true);
    QPair<QString, QString> getJsCssFile(QString path,bool isSinglePage = true);
    void showWarnings(QString content);

private:
    enum QtVersion{
        Qt4,
        Qt5
    };

    enum ExportPath{
        Path_Current,
        Path_SelfDefine
    };

private:
    Ui::ClientOperate *ui;

    QButtonGroup* m_versionButtGroup;
    QButtonGroup* m_dirPathButtGroup;

    ViewModel* m_model;
    ViewDelegate * m_viewDelegate;

    QString m_lastAxureProjectPath;         /*!< 保存上次打开axure的工程目录，作为下次打开的默认位置 */

    const QString cssBaseFileName;
    const QString jsSinglePageFileName;
    const QString jsBaseFileName;

    QList<AxtureProject> m_axureProjList;

    ThreadSwitch *sonThread;
    StartThreads *m_signalFile;
//    ThreadSwitch *sonThread[MAXTHREAD];
};
#endif // CLIENTOPERATE_H

