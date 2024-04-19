import sys
import os
import inspect
import shutil
import subprocess
import unreal
from copy import copy

def get_scriptpath():
    mainDir = os.path.dirname(inspect.stack()[1].filename);
    print(mainDir);

def duplicate():
    # 対象のアセットを取得
    sources = "/RidingSystem/RidingCharacter/Effects/GameplayCue/";
    contents = "/Game/";
    print(unreal.EditorAssetLibrary.list_assets(sources));
    print(unreal.EditorAssetLibrary.list_assets(contents));

    sources = unreal.EditorAssetLibrary.list_assets(sources);

    #unreal.EditorAssetLibrary.duplicate_directory(sources, contents);
    for source in sources:
        objectdata = unreal.EditorAssetLibrary.find_asset_data(source);
        sourcepath = unreal.PackageTools.filename_to_package_name(source);
        targetpath = contents + str(objectdata.package_name); 
        print(source)  
        print(sourcepath)   
        print(targetpath)      
        unreal.EditorAssetLibrary.duplicate_asset(sourcepath, targetpath);

# 二個目以降、絶対パス参照になってエラーになるのででTODO
def duplicate2():
    # 対象のアセットを取得
    sources = "/RidingSystem/RidingCharacter/Effects/GameplayCue/";
    contents = "/Game/RidingSystem/GameplayCue/";
    print(unreal.EditorAssetLibrary.list_assets(sources));
    print(unreal.EditorAssetLibrary.list_assets(contents));

    sources = unreal.EditorAssetLibrary.list_assets(sources);

    #unreal.EditorAssetLibrary.duplicate_directory(sources, contents);
    for source in sources:
        objectdata = unreal.EditorAssetLibrary.find_asset_data(source);
        sourcepath = unreal.PackageTools.filename_to_package_name(source);
        targetpath = contents + str(objectdata.asset_name);
        print(objectdata)
        print(sourcepath) 
        print(targetpath)  
        unreal.EditorAssetLibrary.duplicate_asset(sourcepath, targetpath);

if __name__ == '__main__':
    duplicate();
