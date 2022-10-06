#ifndef TRACE_H
#define TRACE_H

#include <QDebug>


#define TRACE_DBG( format, ... )                                          \
        qDebug( "DBG\t %s +%d (%s)\t ==> " format,                             \
                __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__ );

#define TRACE_INFO( format, ... )                                         \
        qInfo( "INF\t %s +%d (%s)\t ==> " format,                              \
               __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__ );

#define TRACE_WARN( format, ... )                                          \
        qWarning( "WRN\t %s +%d (%s)\t ==> " format,                          \
                   __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__ );

#define TRACE_ERR( format, ... )                                          \
        qCritical( "ERR\t %s +%d (%s)\t ==> " format,                          \
                   __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__ );

#endif  /*< TRACE_H */
