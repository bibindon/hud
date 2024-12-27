// ��ʂɃX�e�[�^�X����\������B
// ���b�N�}���̗̑̓o�[�̂悤�Ȃ���
// hud�Ƃ������O�͗ǂ��Ȃ������C�����邪�ς����Ȃ��̂ł��̂܂܂Ƃ���

#pragma once
#include <string>
#include <vector>
#include <unordered_map>

// �A�C�e�������E��2��ŕ\������
// �����C���x���g���A�E���q��
// �N���b�N������E�����Ɉړ�����B�m�F�͍s��Ȃ��B
namespace NSHud
{
class ISprite
{
public:
    virtual void DrawImage(const int percent,
                           const int x,
                           const int y,
                           const int transparency = 255) = 0;

    virtual void Load(const std::string& filepath) = 0;
    virtual ~ISprite() {};
};

class IFont
{
public:
    virtual void DrawText_(const std::string& msg, const int x, const int y) = 0;
    virtual void Init() = 0;
    virtual ~IFont() {};
};

class StatusItem
{
public:
    void SetName(const std::string& arg);
    std::string GetName() const;

    // 0 ~ 100��101�i�K
    void SetPercent(const int arg);
    int GetPercent() const;

    void SetPercentSub(const int arg);
    int GetPercentSub() const;

    void SetBarVisible(const bool arg);
    bool GetBarVisible() const;

private:

    std::string m_name;
    int m_percent = 0;
    int m_percentSub = 0;
    bool m_visible = false;
};

class hud
{
public:

    void Init(IFont* font, ISprite* sprBack, ISprite* sprMiddle, ISprite* sprFront);
    void Finalize();

    void UpsertStatus(const std::string& name,
                      const int percent,
                      const int percentSub,
                      const bool visible);

    void RemoveStatus(const std::string& name);

    void Draw();
    
private:

    ISprite* m_sprBack;
    ISprite* m_sprMiddle;
    ISprite* m_sprFront;
    IFont* m_font;

    std::vector<StatusItem> m_statusList;

    const int STARTX = 1300;
    const int STARTY = 400;

    const int INTERVAL = 50;
    const int PADDING = 25;
};
}

