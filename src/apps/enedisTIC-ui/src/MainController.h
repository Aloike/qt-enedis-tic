#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

/* Inherited classes */
#include <QObject>

/* System includes */
#include <memory>

/* Libraries includes */
#include <QByteArray>
class   QFile;
class   QSerialPort;

/* Project includes */
#include <enedisTIC/utils.h>

class   MainWindow;

namespace   TIC {
class   FrameBuffer;
class   FrameProcessor;
}



/* ########################################################################## */
/* ########################################################################## */

class   MainController
        :   public  QObject
{
    Q_OBJECT

public:

    MainController(void);
    virtual ~MainController();



protected:
private:

    void    _createConnections(void);
    void    initialize(void);

    void    updateSerialPortsList(void);

    void    inputOpen(const QString& pInputPath, const TIC::TeTICMode& pMode);
    void    inputClose(void);
    bool    inputIsOpen(void) const;
    bool    _openInputFile( const QString& pInputPath );
    bool    _openInputSerialPort(
                    const QString& pInputPath,
                    const TIC::TeTICMode& pMode );

    void    processFrames(void);




private slots:

    void    on_p_serialPort_readyRead(void);
    void    on_ui_inputsList_aboutToShow(void);
    void    on_ui_inputOpenCloseTriggered(bool);



public:
protected:
private:

    size_t          m_datasetsCount;
    size_t          m_framesCount;

    std::unique_ptr<TIC::FrameBuffer>       p_frameBuffer;
    std::unique_ptr<TIC::FrameProcessor>    p_frameProcessor;

    MainWindow*     p_mainWindow;
    QFile*          p_outputFile;
    QSerialPort*    p_serialPort;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< MAINCONTROLLER_H */
