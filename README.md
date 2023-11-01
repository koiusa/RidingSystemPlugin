# RidingSystemPlugin

[![GitHub commit activity](https://img.shields.io/github/commit-activity/m/koiusa/RidingSystemPlugin)](https://github.com/koiusa/RidingSystemPlugin/graphs/commit-activity)
[![GitHub issues](https://img.shields.io/github/issues/koiusa/RidingSystemPlugin)](https://github.com/koiusa/RidingSystemPlugin/issues)
[![GitHub license](https://img.shields.io/github/license/koiusa/RidingSystemPlugin)](https://github.com/koiusa/RidingSystemPlugin/blob/main/LICENSE)

UE5_Plugin

使用手順

1. Unreal Engine 5.2.x　プロジェクトを作成  
  GAMES>Blank

2. プロジェクトの設定にGamePlayTagTableListを追加  
  Edit>ProjectSettings>GamePlayTags
   GamePlayTagTableListに「DT_RidingSystemGamePlayTags」を追加
 
3. プロジェクトのConfigへ、以下のファイルをコピー  
  /Plugins/RidingSystem/Config/DefaultGameplayTags.ini  
  　※GamePalyTag参照の為  

4. プロジェクトのContentへ、以下のディレクトリをコピー  
  /Plugins/RidingSystem/Content/RidingCharacter\Effects\GameplayCue  
  　※Pluginディレクトリから直接参照されないようなので、、、GamePalyCueを参照の為  

5. 依存コンテンツを追加
 Content Drawer＞Add＞Add Feature or Content Pack  
   ThirdPersonを追加  
 　 ※Character,LevelPrototypingを参照している為

　　Contentディレクトリ必須構成
```
├─Content
│  ├─Characters
│  ├─GameplayCue
│  ├─LevelPrototyping
│  ├─ThirdPerson
``` 

6. サンプルマップをオープン  
  /Plugins/RidingSystem/Content/Maps/RidingSystemSampleMap

| 行動 | 操作 |
| ---- | ---- |
| 移動 | WASD |
| ジャンプ | Space |
| スプリント | Left Shift |
| しゃがむ | Ctrl |
| マシン召喚 | Z |  　  
| マシン搭乗 | E | 

---

# サードパーティ ライセンス

以下のマーケットプレイスのNiagaraエフェクトを使用  
https://www.unrealengine.com/marketplace/ja/product/fighter-su33-east
