action_priority_list_t* precombat = get_action_priority_list( "precombat" );
action_priority_list_t* def = get_action_priority_list( "default" );
action_priority_list_t* bear = get_action_priority_list( "bear" );
action_priority_list_t* catweave = get_action_priority_list( "catweave" );
action_priority_list_t* cconvoke = get_action_priority_list( "cconvoke" );
action_priority_list_t* owlweave = get_action_priority_list( "owlweave" );
action_priority_list_t* oconvoke = get_action_priority_list( "oconvoke" );

precombat->add_action( "cat_form,if=(druid.catweave_bear=1)&(cooldown.pause_action.remains|time>30)" );
precombat->add_action( "moonkin_form,if=(!druid.catweave_bear=1)&(cooldown.pause_action.remains|time>30)" );
precombat->add_action( "heart_of_the_wild,if=talent.heart_of_the_wild.enabled" );
precombat->add_action( "prowl,if=(druid.catweave_bear=1)&(cooldown.pause_action.remains|time>30)" );
precombat->add_action( "bear_form,if=(!buff.prowl.up)" );
precombat->add_action( "fleshcraft,if=soulbind.pustule_eruption.enabled|soulbind.volatile_solvent.enabled,interrupt_immediate=1,interrupt_global=1,interrupt_if=soulbind.volatile_solvent" );

def->add_action( "auto_attack,if=!buff.prowl.up" );
def->add_action( "use_item,name=jotungeirr_destinys_call,if=!buff.prowl.up&!covenant.venthyr" );
def->add_action( "use_item,slot=trinket1,if=!buff.prowl.up&!covenant.venthyr&!trinket.1.is.cache_of_acquired_treasures&(!buff.acquired_axe.up&!buff.acquired_sword.up&!buff.acquired_wand.up)" );
def->add_action( "use_item,slot=trinket2,if=!buff.prowl.up&!covenant.venthyr&!trinket.2.is.cache_of_acquired_treasures&(!buff.acquired_axe.up&!buff.acquired_sword.up&!buff.acquired_wand.up)" );
def->add_action( "potion,if=!covenant.venthyr&(((talent.heart_of_the_wild.enabled&buff.heart_of_the_wild.up)&(druid.catweave_bear|druid.owlweave_bear)&!buff.prowl.up)|((buff.berserk_bear.up|buff.incarnation_guardian_of_ursoc.up)&(!druid.catweave_bear&!druid.owlweave_bear)))" );
def->add_action( "run_action_list,name=catweave,if=(target.cooldown.pause_action.remains|time>=30)&druid.catweave_bear=1&((cooldown.convoke_the_spirits.remains<=1)&(buff.incarnation_guardian_of_ursoc.down&buff.berserk_bear.down)|(buff.incarnation_guardian_of_ursoc.down&buff.berserk_bear.down)&(cooldown.thrash_bear.remains>0&cooldown.mangle.remains>0&dot.moonfire.remains>=gcd+0.5)|(buff.cat_form.up&energy>25)|(buff.heart_of_the_wild.up&energy>90))","Catweaving action list will be ran if,we’re not being meleed, mangle/thrash are on cd, rage is below 40, zerk and incarnation are down, or if, we're in catform and energy is above 25, or HotW is active" );
def->add_action( "run_action_list,name=owlweave,if=(target.cooldown.pause_action.remains|time>=30)&((druid.owlweave_bear=1)&buff.incarnation_guardian_of_ursoc.down&buff.berserk_bear.down&cooldown.starsurge.up)","Owlweaving action list will be ran if, we’re not being meleed, Starsurge cd is up zerk and incarnation are down." );
def->add_action( "run_action_list,name=owlweave,if=(target.cooldown.pause_action.remains|time>=30)&((druid.owlweave_bear=1)&buff.incarnation_guardian_of_ursoc.down&buff.berserk_bear.down&cooldown.starsurge.up)","If we’re talented into convoke and we don't want to catweave/owlweave, and we have balance/feral affinity talented, Whenever convoke cd is up we switch into affinity form to cast it, here moonkin form." );
def->add_action( "run_action_list,name=cconvoke,if=(target.cooldown.pause_action.remains|time>=30)&((talent.convoke_the_spirits.enabled)&(cooldown.convoke_the_spirits.remains<=1)&(!druid.catweave_bear=1))","If we're talented into convoke and we don't want to catweave/owlweave, and we have balance/feral affinity talented, Whenever convoke cd is up we switch into affinity form to cast it, here catform form." );
def->add_action( "run_action_list,name=bear" );

bear->add_action( "bear_form,if=!buff.bear_form.up" );
bear->add_action( "heart_of_the_Wild,if=talent.heart_of_the_wild.enabled" );
bear->add_action( "moonfire,cycle_targets=1,if=((!ticking&time_to_die>12)|(refreshable&time_to_die>12))&active_enemies<6" );
bear->add_action( "barkskin,if=buff.bear_form.up" );
bear->add_action( "ravenous_frenzy,if=(((trinket.1.is.cache_of_acquired_treasures|trinket.2.is.cache_of_acquired_treasures)&buff.acquired_axe.up))|(!trinket.1.is.cache_of_acquired_treasures&!trinket.2.is.cache_of_acquired_treasures)" );
bear->add_action( "convoke_the_spirits,if=!druid.catweave_bear&!druid.owlweave_bear&(trinket.1.is.cache_of_acquired_treasures|trinket.2.is.cache_of_acquired_treasures)" );
bear->add_action( "incarnation,if=(!covenant.venthyr&((trinket.1.is.cache_of_acquired_treasures|trinket.2.is.cache_of_acquired_treasures)&buff.acquired_axe.up))" );
bear->add_action( "use_item,slot=trinket1,if=trinket.1.is.cache_of_acquired_treasures&buff.acquired_axe.up" );
bear->add_action( "use_item,slot=trinket2,if=trinket.2.is.cache_of_acquired_treasures&buff.acquired_axe.up" );
bear->add_action( "use_item,name=gavel_of_the_first_arbiter" );
bear->add_action( "use_item,name=wraps_of_electrostatic_potential" );
bear->add_action( "use_item,name=ring_of_collapsing_futures" );
bear->add_action( "use_item,name=jotungeirr_destinys_call,if=covenant.venthyr" );
bear->add_action( "use_item,slot=trinket1,if=!buff.prowl.up&covenant.venthyr&!trinket.1.is.cache_of_acquired_treasures&(!buff.acquired_axe.up&!buff.acquired_sword.up&!buff.acquired_wand.up)|!buff.prowl.up&!covenant.venthyr&!trinket.1.is.cache_of_acquired_treasures&(!buff.acquired_axe.up&!buff.acquired_sword.up&!buff.acquired_wand.up)" );
bear->add_action( "use_item,slot=trinket2,if=!buff.prowl.up&covenant.venthyr&!trinket.2.is.cache_of_acquired_treasures&(!buff.acquired_axe.up&!buff.acquired_sword.up&!buff.acquired_wand.up)|!buff.prowl.up&!covenant.venthyr&!trinket.2.is.cache_of_acquired_treasures&(!buff.acquired_axe.up&!buff.acquired_sword.up&!buff.acquired_wand.up)" );
bear->add_action( "potion,if=covenant.venthyr&buff.incarnation.remains>=24&buff.incarnation.remains<=25" );
bear->add_action( "convoke_the_spirits,if=!druid.catweave_bear&!druid.owlweave_bear" );
bear->add_action( "berserk_bear,if=(buff.ravenous_frenzy.up|!covenant.venthyr)" );
bear->add_action( "incarnation,if=(buff.ravenous_frenzy.up|!covenant.venthyr)" );
bear->add_action( "berserking,if=(buff.berserk_bear.up|buff.incarnation_guardian_of_ursoc.up)" );
bear->add_action( "empower_bond" );
bear->add_action( "adaptive_swarm,if=(!dot.adaptive_swarm_damage.ticking&!action.adaptive_swarm_damage.in_flight&(!dot.adaptive_swarm_heal.ticking|dot.adaptive_swarm_heal.remains>3)|dot.adaptive_swarm_damage.stack<3&dot.adaptive_swarm_damage.remains<5&dot.adaptive_swarm_damage.ticking)" );
bear->add_action( "fleshcraft,if=soulbind.pustule_eruption.enabled&((cooldown.thrash_bear.remains>0&cooldown.mangle.remains>0)&(dot.moonfire.remains>=3)&(buff.incarnation_guardian_of_ursoc.down&buff.berserk_bear.down&buff.galactic_guardian.down))|soulbind.volatile_solvent.enabled,interrupt_immediate=1,interrupt_global=1,interrupt_if=soulbind.volatile_solvent&(cooldown.thrash_bear.remains>0&cooldown.mangle.remains>0)" );
bear->add_action( "rage_of_the_sleeper,if=(cooldown.pause_action.remains)" );
bear->add_action( "berserking,if=(buff.berserk_bear.up|buff.incarnation_guardian_of_ursoc.up)" );
bear->add_action( "ironfur,target_if=!debuff.tooth_and_claw_debuff.up,if=!buff.ironfur.up&!cooldown.pause_action.remains" );
bear->add_action( "moonfire,if=buff.galactic_guardian.up&buff.galactic_guardian.remains<=gcd+0.5" );
bear->add_action( "thrash_bear,target_if=refreshable|dot.thrash_bear.stack<3|active_enemies>=4" );
bear->add_action( "swipe,if=buff.incarnation_guardian_of_ursoc.down&buff.berserk_bear.down&active_enemies>=4" );
bear->add_action( "maul,if=((buff.incarnation.up)&active_enemies<3&(buff.tooth_and_claw.stack>=2))|((buff.tooth_and_claw.up&buff.tooth_and_claw.remains<1.5)&active_enemies<3)" );
bear->add_action( "maul,if=active_enemies<3&buff.vicious_cycle_maul.stack>=3|active_enemies<3&!talent.vicious_cycle_maul.enabled" );
bear->add_action( "mangle,if=(buff.incarnation.up&active_enemies<=3)|((rage<90)&active_enemies<3)|((rage<85)&active_enemies<3&talent.soul_of_the_forest.enabled)|(buff.gore.up)" );
bear->add_action( "thrash_bear,if=active_enemies>1" );
bear->add_action( "pulverize,target_if=dot.thrash_bear.stack>2" );
bear->add_action( "thrash_bear" );
bear->add_action( "moonfire,if=active_enemies<2" );
bear->add_action( "swipe_bear" );

catweave->add_action( "heart_of_the_wild,if=talent.heart_of_the_wild.enabled&!buff.heart_of_the_wild.up&!buff.cat_form.up","if you read this know that Kitch is a dummy" );
catweave->add_action( "cat_form,if=!buff.cat_form.up" );
catweave->add_action( "rake,if=buff.prowl.up" );
catweave->add_action( "heart_of_the_wild,if=talent.heart_of_the_wild.enabled&!buff.heart_of_the_wild.up" );
catweave->add_action( "empower_bond,if=druid.catweave_bear" );
catweave->add_action( "rake,if=dot.rake.refreshable|energy<45" );
catweave->add_action( "rip,if=dot.rip.refreshable&combo_points>=1" );
catweave->add_action( "convoke_the_spirits" );
catweave->add_action( "ferocious_bite,if=combo_points>=4&energy>50" );
catweave->add_action( "shred,if=combo_points<=5" );
catweave->add_action( "adaptive_swarm,if=(!dot.adaptive_swarm_damage.ticking&!action.adaptive_swarm_damage.in_flight&(!dot.adaptive_swarm_heal.ticking|dot.adaptive_swarm_heal.remains>3)|dot.adaptive_swarm_damage.stack<3&dot.adaptive_swarm_damage.remains<5&dot.adaptive_swarm_damage.ticking)" );
catweave->add_action( "fleshcraft,if=soulbind.pustule_eruption.enabled&energy<35|soulbind.volatile_solvent.enabled,interrupt_immediate=1,interrupt_global=1,interrupt_if=soulbind.volatile_solvent&energy<35" );
catweave->add_action( "swipe_cat" );

cconvoke->add_action( "heart_of_the_wild,if=talent.heart_of_the_wild.enabled&!buff.heart_of_the_wild.up&!buff.cat_form.up" );
cconvoke->add_action( "cat_form,if=!buff.cat_form.up" );
cconvoke->add_action( "convoke_the_spirits" );

owlweave->add_action( "heart_of_the_wild,if=talent.heart_of_the_wild.enabled&!buff.heart_of_the_wild.up&!buff.cat_form.up" );
owlweave->add_action( "moonfire,if=buff.galactic_guardian.up&buff.galactic_guardian.remains<=gcd+1" );
owlweave->add_action( "sunfire,if=dot.sunfire.refreshable" );
owlweave->add_action( "starsurge" );

oconvoke->add_action( "heart_of_the_wild,if=talent.heart_of_the_wild.enabled&!buff.heart_of_the_wild.up&!buff.moonkin_form.up" );
oconvoke->add_action( "moonkin_form,if=!buff.moonkin_form.up" );
oconvoke->add_action( "convoke_the_spirits" );
