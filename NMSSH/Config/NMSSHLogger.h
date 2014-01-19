#define NMSSHLogVerbose(frmt, ...) [[NMSSHLogger logger] logVerbose:[NSString stringWithFormat:frmt, ##__VA_ARGS__]]
#define NMSSHLogInfo(frmt, ...) [[NMSSHLogger logger] logInfo:[NSString stringWithFormat:frmt, ##__VA_ARGS__]]
#define NMSSHLogWarn(frmt, ...) [[NMSSHLogger logger] logWarn:[NSString stringWithFormat:frmt, ##__VA_ARGS__]]
#define NMSSHLogError(frmt, ...) [[NMSSHLogger logger] logError:[NSString stringWithFormat:frmt, ##__VA_ARGS__]]

typedef NS_OPTIONS(NSUInteger, NMSSHLogLevel) {
    NMSSHLogLevelVerbose = (1 << 0 | 1 << 1 | 1 << 2 | 1 << 3),
    NMSSHLogLevelInfo    = (1 << 1 | 1 << 2 | 1 << 3),
    NMSSHLogLevelWarn    = (1 << 2 | 1 << 3),
    NMSSHLogLevelError   = (1 << 3)
};

/**
 NMSSHLogger provides the functionality to customize the framework logging.
 */
@interface NMSSHLogger : NSObject

/// ----------------------------------------------------------------------------
/// @name Retrieve the shared logger
/// ----------------------------------------------------------------------------

/**
 Retrieve the shared logger instance

 @returns Shared logger
 */
+ (NMSSHLogger *)logger;

/// ----------------------------------------------------------------------------
/// @name Logger settings
/// ----------------------------------------------------------------------------

/**
 The block called to print the log message.

 The default implementation print the log
 message using NSLog.

 The block takes two argument:

 _level_ - Log level<br>
 _format_ - Log message
 */
@property (nonatomic, copy) void (^logBlock)(NMSSHLogLevel level, NSString *format);

/** The maximum log level */
@property (nonatomic, assign) NMSSHLogLevel logLevel;

/** Enable or disable the logging feature */
@property (nonatomic, assign, getter = isEnabled) BOOL enabled;

/// ----------------------------------------------------------------------------
/// @name Logging
/// ----------------------------------------------------------------------------

/**
 Log with verbose level

 @param format Log message
 */
- (void)logVerbose:(NSString *)format;

/**
 Log with info level

 @param format Log message
 */
- (void)logInfo:(NSString *)format;

/**
 Log with warn level

 @param format Log message
 */
- (void)logWarn:(NSString *)format;

/**
 Log with error level

 @param format Log message
 */
- (void)logError:(NSString *)format;

@end
