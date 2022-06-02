#ifndef TRACE_H
#define TRACE_H

#include <QDebug>


#define TRACE_DBG_BASE( format, ... )                                          \
        qDebug( "DBG\t %s +%d (%s)\t ==> " format,                             \
                __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__ );

#define TRACE_INFO_BASE( format, ... )                                         \
        qInfo( "INF\t %s +%d (%s)\t ==> " format,                              \
               __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__ );

#define TRACE_WARN_BASE( format, ... )                                          \
        qWarning( "WRN\t %s +%d (%s)\t ==> " format,                          \
                   __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__ );

#define TRACE_ERR_BASE( format, ... )                                          \
        qCritical( "ERR\t %s +%d (%s)\t ==> " format,                          \
                   __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__ );

#endif  /*< TRACE_H */
