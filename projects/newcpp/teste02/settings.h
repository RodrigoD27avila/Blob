#ifndef Settings_H_Included
#define Settings_H_Included

class Settings {
public:
	static void setWidth(int width);
	static int  getWidth();
	
	static void setHeight(int height);
	static int  getHeight();
private:
	Settings();
//	~Settings();
	Settings(const Settings &s);
	Settings &operator=(const Settings &s);
};

#endif // Settings_H_Included
