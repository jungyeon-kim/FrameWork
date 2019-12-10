#pragma once

// Singleton
class ScnMgr final
{
private:
	static constexpr int column{ wndSizeY / 100 }, row{ wndSizeX / 100 };

	int levelTile[column][row]{};
	int levelNameIdx{};
	bool readyToGoNextLevel{};

	std::ifstream tileData{};
	std::vector<int> texID{};

	static ScnMgr* instance;
private:
	ScnMgr();
	~ScnMgr();
public:
	static ScnMgr* getInstance();

	void init();
	void update(float eTime);
	void render();

	bool readTileData(std::string fileName);
	void setLevel(std::string fileName);

	bool getReadyToGoNextLevel() const;
	void setReadyToGoNextLevel(bool boolean);
};

