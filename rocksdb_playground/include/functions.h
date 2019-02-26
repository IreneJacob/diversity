#include <rocksdb/c.h>

struct rocksdb_txdb_params {
    rocksdb_transactiondb_t *tx_db;
    rocksdb_options_t *options;
    rocksdb_transactiondb_options_t *txdb_options;
    rocksdb_writeoptions_t *write_options;
    rocksdb_readoptions_t *read_options;
    rocksdb_transaction_t *tx;
    rocksdb_transaction_options_t* tx_options;
};

void init_rocksdb_txdb(void);
int txdb_deconstruct(void);
int open_txdb(char* db_path);
int close_txdb(void);
int destroy_txdb(char* db_path);
int begin_tx(void);
int commit_tx(void);
int delete_tx(void);
int handle_tx_read(char *key, size_t keylen);
int handle_tx_write(char *key, size_t keylen, char *val, size_t vallen);
int handle_tx_delete(char *key, size_t keylen);
int handle_tx_list(void);
int handle_txdb_list(void);
int handle_save(void);
int handle_rollback(void);

extern struct rocksdb_txdb_params txrocks;
