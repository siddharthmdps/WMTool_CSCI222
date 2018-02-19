

class Encryption{

	public: int EncryptionKey, DecryptionKey;
			bool EncryptionStatus;

			Encryption();
			~Encryption();

			void encryptUserFile();
			void decryptUserFile();
			
			void encryptStockFile();
			void decryptStockFile();



};




